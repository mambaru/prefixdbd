
/*#include "repli_hub.hpp"
#include "repli_channel.hpp"
#include <iostream>
#include <comet/logger.hpp>
*/
#include "repli_hub.hpp"
#include "repli_client.hpp"

namespace wfc{
  
//class repli_channel{};

void repli_hub::split_channel(const std::string& orig, std::string& channel, std::string& client_id)
{
  std::string::size_type pos = orig.find(_separator);
  if ( pos!=std::string::npos )
  {
    channel = orig.substr(0, pos);
    client_id = orig.substr(pos + _separator.size());
  }
  else
  {
    client_id.clear();
    channel = orig;
  }
  
}

repli_hub::~repli_hub()
{
  this->stop();
}

void repli_hub::initialize(const std::string& separator)
{
  _separator = separator;
}

void repli_hub::stop()
{
  /*for (const auto& i: _channel_map)
    delete i.second;*/
  _channel_map.clear();
}

void repli_hub::describe( size_t )
{
  
}
  
void repli_hub::subscribe(request_subscribe_ptr, subscribe_callback, size_t , publish_handler )
{
  
}

void repli_hub::publish(request_publish_ptr, publish_callback)
{
  
}

void repli_hub::publish(request_multi_publish_ptr, multi_publish_callback)
{
  
}
  
void repli_hub::load(request_load_ptr, load_callback )
{
  
}

void repli_hub::load(request_multi_load_ptr, multi_load_callback )
{
  
}

void repli_hub::query(request_query_ptr, query_callback )
{
  
}
  
void repli_hub::notify(request_notify_ptr, notify_callback )
{
  
}


/*
status::type repli_hub::subscribe(const std::string& orig_channel, isubscriber* subject, ipubsub_callback* )
{
  std::string client_id;
  std::string channel;
  this->split_channel(orig_channel, channel, client_id);
  auto itr = _channel_map.find(channel);
  if ( itr == _channel_map.end() )
    itr = _channel_map.insert( std::make_pair(channel, new repli_channel(channel, _separator)) ).first;

  bool flag = itr->second->subscribe(client_id, subject);
  COMMON_LOG_MESSAGE("repli_hub::subscribe: " << orig_channel << " - " << (flag ? "READY" : "FORBIDDEN") )
  
  return flag ? status::ready : status::forbidden;
}

status::type repli_hub::describe(const std::string& orig_channel, isubscriber* subject, ipubsub_callback* )
{
  std::string client_id;
  std::string channel;
  this->split_channel(orig_channel, channel, client_id);
  auto itr = _channel_map.find(channel);
  if ( itr == _channel_map.end() )
    return status::not_found;

  bool flag = itr->second->describe(client_id, subject);
  COMMON_LOG_MESSAGE("repli_hub::describe: " << orig_channel << " - " << (flag ? "READY" : "NOT_FOUND") )
  return flag ? status::ready : status::not_found;
}

status::type repli_hub::describe(isubscriber* subject, ipubsub_callback* )
{
  // Подписчиков репликации предволагаеться немного, поэтому тупо перебираем
  for (const auto& i : _channel_map )
    i.second->describe(subject);
  return status::ready;
}

status::type repli_hub::publish(const message& m, ipubsub_callback* )
{
  auto itr = _channel_map.find(m.channel);
  
  if ( itr == _channel_map.end() )
    return status::not_found;

  itr->second->publish(m);
  
  return status::ready;
}

status::type repli_hub::publish(const std::vector<message>& , ipubsub_callback* )
{
  return status::not_support;
}

pubsub_result repli_hub::load(const load_request& , std::vector<message_base>& , ipubsub_callback*  )
{
  return pubsub_result(status::not_support, 0);
}

status::type repli_hub::load(const std::vector<load_request>& , std::vector<load_response>& , ipubsub_callback* )
{
  return status::not_support;
}

status::type repli_hub::custom_request( const ::mamba::comet::custom_request& , custom_response& , ipubsub_callback* )
{
  return status::not_support;
  
}

status::type repli_hub::custom_notify( const ::mamba::comet::custom_request& , ipubsub_callback*  )
{
  return status::not_support;
}
*/

void repli_hub::idle()
{
  /*!!!
  for (const auto& i : _channel_map )
    i.second->idle();
  */
}

}