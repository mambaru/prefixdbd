#pragma once

#include "repli_client.hpp"
#include <map>
#include <string>
#include <wfc/memory.hpp>

namespace wfc{

class repli_channel
{
  typedef pubsub::message message_type;
  typedef std::unique_ptr<message_type> message_ptr;

  typedef std::map<std::string, std::unique_ptr<repli_client> > client_map;
  typedef pubsub::ipubsub::publish_handler publish_handler;

public:
  
  virtual ~repli_channel()
  {
    this->clear();
  }

  repli_channel(const std::string& channel/*, const std::string& separator*/)
    : _channel(channel)
    //, _separator(separator)
  {}

  bool subscribe(const std::string& client_id, size_t client_io_id,  publish_handler handler)
  {
    auto itr = _clients.find(client_id);
    if ( itr == _clients.end() )
      itr = _clients.insert( std::make_pair(client_id, std::make_unique<repli_client>(_channel, client_id) ) ).first;
    return itr->second->subscribe(client_io_id, handler);
  }

  bool describe(const std::string& client_id, size_t client_io_id)
  {
    auto itr = _clients.find(client_id);
    if ( itr == _clients.end() )
      return false;

    if ( !itr->second->fell(client_io_id) )
      return false;

    _clients.erase(itr);
    
    return true;
  }
  
  bool fell(size_t client_io_id)
  {
    bool flag = false;
    for (const auto& i : _clients)
      flag |= i.second->fell(client_io_id);
    return flag;
  }

  bool publish(message_ptr m )
  {
    if ( _clients.empty() )
      return false;
    
    auto last = ( ++_clients.rbegin() ).base();
    auto itr = _clients.begin();
    for (;itr != _clients.end(); ++itr)
    {
      if (itr == last )
      {
        itr->second->publish( std::move(m) );
      }
      else
      {
        auto mm = std::make_unique<message_type>(*m);
        itr->second->publish( std::move(m) );
      }
    }
    
    return true;
    /*
    message mm = m;
    for (const auto& i: _clients)
    {
      mm.channel = m.channel;
      mm.channel += _separator;
      mm.channel += i.first;
      i.second->publish(mm);
    }
    return true;
      */
  }

  void clear()
  {
    _clients.clear();
  }

  void idle()
  {
    for (const auto& i: _clients)
      i.second->idle();
  }

private:
   client_map _clients;
   std::string _channel;
   // std::string _separator;

};

}
