#include "repli_hub/hub/repli_client.hpp"
#include <atomic>
#include <chrono>
#include <thread>

using namespace ::wfc;
using namespace ::wfc::pubsub;

int counter = 0;
std::shared_ptr<repli_client> cli;

void handler(ipubsub::request_publish_ptr req, ipubsub::publish_callback cb)
{
  if ( req->channel!="test_channel" )
    abort();
  
  ++counter;
  auto resp = std::make_unique<pubsub::response::publish>();
  if ( counter == 1 )
  {
    resp->status = status::bad_gateway;
  }
  else if ( counter == 2 )
  {
    resp->status = status::bad_gateway;
    cli->fell(1);
  }
  else if ( counter == 3 )
  {
    resp->status = status::ready;
    cli->fell(1);
  }
  else
  {
    resp->status = status::ready;
  }
    
  cb( std::move(resp) );
  
}

void send_message()
{
  auto m = std::make_unique<pubsub::request::publish>();
  m->channel = "test_channel";
  cli->publish( std::move(m) );
}

int main()
{
  cli = std::make_shared<repli_client>("test_channel", "test_client");
  send_message();
  cli->subscribe(1, handler); // ++counter
  cli->fell(1);
  cli->subscribe(1, handler); // ++counter
  cli->subscribe(1, handler); // ++counter
  cli->subscribe(1, handler); 
  
  send_message(); // ++counter
  cli->fell(1);
  
  send_message();
  send_message();
  send_message();
  
  cli->subscribe(1, handler); // counter+=3
  
  std::cout << "counter=" << counter << std::endl;
  if ( counter!=7 )
    abort();
  return 0;
  
}