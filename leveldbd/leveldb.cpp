#include "leveldbd_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <leveldb/leveldb_package.hpp>
#include <prefixdb/prefixdb_package.hpp>

int main(int argc, char* argv[])
{
  return ::wfc::wfc<leveldbd_build_info>(::wfc::wfcroot(
    {
      std::make_shared< ::wamba::leveldb::leveldb_package >(),
      std::make_shared< ::wamba::prefixdb::prefixdb_package >()
    }
  )).run(argc, argv);
}
