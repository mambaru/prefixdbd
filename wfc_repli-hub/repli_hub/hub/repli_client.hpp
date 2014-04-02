#pragma once

#include <wfc/logger.hpp>
#include <wfc/pubsub/ipubsub.hpp>
#include <wfc/io/io_base.hpp>
#include <list>
#include <mutex>

namespace wfc{

class repli_client
{
  typedef pubsub::message message_type;
  typedef std::unique_ptr<message_type> message_ptr;
  typedef std::list< message_ptr > message_list;
  typedef pubsub::ipubsub::publish_handler publish_handler;
  typedef std::mutex mutex_type;
  
public:
  
  virtual ~repli_client();

  repli_client(const std::string& channel, const std::string& client_id);

  bool subscribe(size_t client_io_id, publish_handler handler);

  // клиент отвалился
  bool fell(size_t client_io_id);
  
  void publish(message_ptr m );

  void idle();

private:

  void process_queue();
  void result_handler( ::wfc::pubsub::ipubsub::response_publish_ptr resp );
  
  publish_handler _publish_handler;
  message_list _messages;

  // Нужны только для отладки
  std::string _channel;
  std::string _client_id;
  size_t _client_io_id;

  size_t _sended;
  size_t _confirmed;
  mutable mutex_type _mutex;
};

}
