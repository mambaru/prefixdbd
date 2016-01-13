#include "prefixdbd_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <prefixdb_package.hpp>

int main(int argc, char* argv[])
{
  return ::wfc::wfc<prefixdbd_build_info>(::wfc::wfcroot(
    {
      std::make_shared< ::wamba::prefixdb::prefixdb_package >()
    }
  )).run(argc, argv);
}
