#pragma once


#include <wfc/module/multi_instance.hpp>
#include "repli_hub_instance.hpp"
#include "repli_hub_config_json.hpp"
#include "build_info.h"

namespace wfc{

class repli_hub_module
  : public multi_instance<repli_hub_build_info, repli_hub_config_json::type, repli_hub_instance>
{
  
};

}