#pragma once
#include <wfc/pubsub/ipubsub.hpp>
#include <memory>
#include <map>

namespace wfc{

class repli_channel{};
  
class repli_hub:
  public pubsub::ipubsub
{
  typedef std::map<std::string, std::unique_ptr<repli_channel> > channel_map;
public:
  
  virtual ~repli_hub();

  void initialize(const std::string& separator);

  void stop();

  void idle();

  /// ipubsub
  
  virtual void describe( size_t subscriber_id );
  
  virtual void subscribe(request_subscribe_ptr, subscribe_callback, size_t subscriber_id, publish_handler );

  virtual void publish(request_publish_ptr, publish_callback);

  virtual void publish(request_multi_publish_ptr, multi_publish_callback);
  
  virtual void load(request_load_ptr, load_callback );

  virtual void load(request_multi_load_ptr, multi_load_callback );

  virtual void query(request_query_ptr, query_callback );
  
  virtual void notify(request_notify_ptr, notify_callback );


  /*
  virtual status::type subscribe(const std::string& channel, isubscriber* subject, ipubsub_callback* callback);

  virtual status::type describe(const std::string& channel, isubscriber* subject, ipubsub_callback* callback);

  virtual status::type describe(isubscriber* subject, ipubsub_callback* callback);

  virtual status::type publish(const message& m, ipubsub_callback* callback);

  virtual status::type publish(const std::vector<message>& ms, ipubsub_callback* callback);

  virtual pubsub_result load(const load_request& lc, std::vector<message_base>& m, ipubsub_callback* callback );

  virtual status::type load(const std::vector<load_request>& lc, std::vector<load_response>& cr, ipubsub_callback* callback);

  virtual status::type custom_request( const ::mamba::comet::custom_request& req, custom_response& resp, ipubsub_callback* );

  virtual status::type custom_notify( const ::mamba::comet::custom_request& , ipubsub_callback*  );
  */
  ///

private:
  void split_channel(const std::string& orig, std::string& channel, std::string& client_id);
  std::string _separator;
  channel_map _channel_map;
};

}
