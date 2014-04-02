
#include <wfc/logger.hpp>
#include <wfc/pubsub/ipubsub.hpp>
#include <wfc/io/io_base.hpp>
#include <list>
#include <mutex>
#include "repli_client.hpp"
namespace wfc{

repli_client::~repli_client()
{
}

repli_client::repli_client(const std::string& channel, const std::string& client_id)
  : _publish_handler(nullptr)
  , _channel(channel)
  , _client_id(client_id)
  , _client_io_id(0)
  , _sended(0)
  , _confirmed(0)
{
}

bool repli_client::subscribe(size_t client_io_id, publish_handler handler)
{
  {
    std::lock_guard<mutex_type> lk(_mutex);
    if ( _publish_handler!=nullptr )
    {
      DAEMON_LOG_WARNING("repli_client: Попытка повторной подписки для " << _channel << "$$" << _client_id );
      return false;
    }
    DAEMON_LOG_MESSAGE("repli_client: Slave подключен для " << _channel << "$$" << _client_id );
    _publish_handler = handler;
    _client_io_id = client_io_id;
  }
  this->process_queue();
  return true;
}

// клиент отвалился
bool repli_client::fell(size_t client_io_id)
{
  std::lock_guard<mutex_type> lk(_mutex);
  
  if ( _client_io_id == 0 )
  {
    DAEMON_LOG_WARNING("repli_client: Повторный вызов fell для " << _channel << "$$" << _client_id );
    return false;
  }
  
  if ( _client_io_id != client_io_id )
  {
    DAEMON_LOG_WARNING("repli_client: Неверный вызов fell для " << _channel << "$$" << _client_id );
    return false;
  }
  
  _publish_handler = nullptr;
  _client_io_id = 0;

  return true;
}

void repli_client::publish(message_ptr m )
{
  publish_handler handler = nullptr;
  ::wfc::pubsub::ipubsub::request_publish_ptr req = nullptr;
  
  {
    std::lock_guard<mutex_type> lk(_mutex);
    if ( _client_io_id!=0 && _messages.empty() )
    {
      handler = _publish_handler;
      if (handler!=nullptr)
      {
        ++_sended;
        req = std::make_unique< ::wfc::pubsub::request::publish>();
        req->channel = _channel;
        static_cast<message_type&>(*req) = *m;
      }
    }
    _messages.push_back( std::move(m) );
  }
  
  if ( handler )
  {
    handler( std::move(req), std::bind( &repli_client::result_handler, this, std::placeholders::_1 ) );
  }
}

void repli_client::idle()
{
  std::lock_guard<mutex_type> lk(_mutex);
  if ( _publish_handler == 0 )
  {
    DAEMON_LOG_WARNING("repli_client: Subscriber disconnected. Queue size=" << _messages.size() << " для " << _channel << "$$" << _client_id << " sended=" << _sended << " confirmed=" << _confirmed);
  }
  else if ( _messages.size() > 10 )
  {
    DAEMON_LOG_MESSAGE("repli_client: Queue size=" << _messages.size() << " для " << _channel << "$$" << _client_id << " sended=" << _sended << " confirmed=" << _confirmed );
  }
  else if ( _messages.size() > 100 )
  {
    DAEMON_LOG_WARNING("repli_client: Queue size=" << _messages.size() << " для " << _channel << "$$" << _client_id << " sended=" << _sended << " confirmed=" << _confirmed);
  }
}

void repli_client::process_queue()
{
  publish_handler handler = nullptr;
  ::wfc::pubsub::ipubsub::request_publish_ptr req = nullptr;
  //message_ptr m;
  {
    std::lock_guard<mutex_type> lk(_mutex);
    if ( _messages.empty() )
      return;
    handler = _publish_handler;
    //m = std::make_unique<message_type>( *(_messages.front()) );
    if ( handler!= nullptr )
    {
      ++_sended;
      req = std::make_unique< ::wfc::pubsub::request::publish>();
      req->channel = _channel;
      static_cast<message_type&>(*req) = *(_messages.front());

    }
  }
  
  if (handler!=nullptr)
    handler( std::move(req), std::bind( &repli_client::result_handler, this, std::placeholders::_1  ));
}

void repli_client::result_handler( ::wfc::pubsub::ipubsub::response_publish_ptr resp )
{
  bool ready = false;
  {
    std::lock_guard<mutex_type> lk(_mutex);
    if ( resp->status == ::wfc::pubsub::status::ready )
    {
      // На тот случай если клиент отвалился в момен вызова publish
      // и fell еще не произошел
      _messages.pop_front();
      ++_confirmed;
      ready = true;
    }
    else if ( resp->status != ::wfc::pubsub::status::bad_gateway )
    {
      DAEMON_LOG_ERROR("repli_client: Ошибка репликации " << _channel << "$$" << _client_id << ": status=" << static_cast<int>(resp->status) );
      _messages.pop_front();
    }
    else
    {
      DAEMON_LOG_WARNING("repli_client: Bad Gateway " << _channel << "$$" << _client_id << ": status=" << static_cast<int>(resp->status) );
      --_sended;
    }
  }
  if (ready)
    this->process_queue();
}

}
