#include <wfc/wfc.hpp>
#include <core/core_module.hpp>
#include <startup/startup_module.hpp>
#include <config/config_module.hpp>
#include <logger/logger_module.hpp>
#include <hub/hub_module.hpp>
#include "build_info.h"
#include <core/build_info.h>

#include <module/demo_module.hpp>


int main(int argc, char* argv[])
{
  return wfc::wfc(
    demod_build_info_string,
    {
      { "startup", std::make_shared< wfc::startup_module   >() },
      { "core",    std::make_shared< wfc::core_module   >() },
      { "config",  std::make_shared< wfc::config_module >() },
      { "logger",  std::make_shared< wfc::logger_module >() }, 
      { "hub",     std::make_shared< wfc::hub_module    >() }, 
      { "demo",    std::make_shared< wamba::demo::demo_module >() }
    }
  ).run(argc, argv);
}
