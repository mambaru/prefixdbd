#include "repli_hub_instance.hpp"
#include "hub/repli_hub.hpp"
#include <wfc/memory.hpp>


namespace wfc{

repli_hub_instance::~repli_hub_instance()
{
  
}

repli_hub_instance::repli_hub_instance(const std::string& name, std::weak_ptr<global> g, const repli_hub_config& conf)
  : _name(name)
  , _global(g)
{
  this->reconfigure(conf);
}

void repli_hub_instance::reconfigure(const repli_hub_config& conf)
{
  _conf = conf;
  
  if ( _conf.enabled && !_repli_hub)
  {
    if ( !_repli_hub )
    {
      _repli_hub = std::make_shared<repli_hub>();
    }
  }
  else if ( !_conf.enabled )
  {
    _repli_hub.reset(  );
  }


  if ( auto gg = _global.lock() )
  {
    if (auto ps = gg->pubsubs.lock() )
    {
      if ( _conf.enabled )
      {
        ps->set(_conf.pubsub_name, _repli_hub);
      }
      else
      {
        ps->erase(_conf.pubsub_name);
      }
    }
  }
  
}

void repli_hub_instance::initialize()
{
  
}

void repli_hub_instance::start()
{

}

void repli_hub_instance::stop()
{
  
}

repli_hub_config repli_hub_instance::create_config(std::string)
{
  repli_hub_config conf;
  conf.enabled = true;
  conf.pubsub_name = "repli_hub1";
  return conf;
}




  
}