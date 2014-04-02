#pragma once

#include "repli_hub_config.hpp"
#include <wfc/json/json.hpp>
#include <wfc/json/name.hpp>

namespace wfc{

struct repli_hub_config_json
{
  FAS_NAME(enabled)
  FAS_NAME(pubsub_name)
  
  typedef json::object<
    repli_hub_config,
    fas::type_list_n<
       json::member<n_enabled, repli_hub_config, bool, &repli_hub_config::enabled>, 
       json::member<n_pubsub_name, repli_hub_config, std::string, &repli_hub_config::pubsub_name>
    >::type
  > type;
  
  typedef type::serializer serializer; 
};

}
