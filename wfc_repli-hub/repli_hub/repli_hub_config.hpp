#pragma once
#include <string>

namespace wfc{

struct repli_hub_config
{
  bool enabled = true;
  std::string pubsub_name;
};

}
