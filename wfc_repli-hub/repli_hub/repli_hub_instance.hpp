#pragma once


#include "repli_hub_config.hpp"
#include <wfc/core/global.hpp>
#include <string>
#include <memory>

namespace wfc{
  
class repli_hub;
  
class repli_hub_instance
{
public:
  virtual ~repli_hub_instance();
  repli_hub_instance(const std::string& name, std::weak_ptr<global> g, const repli_hub_config& conf);
  void reconfigure(const repli_hub_config& conf);
  void initialize();
  void start();
  void stop();
  
  static repli_hub_config create_config(std::string type);
private:
  std::string _name;
  std::weak_ptr<global> _global;
  repli_hub_config _conf;
  std::shared_ptr<repli_hub> _repli_hub;
  
};

}