#include "prefixdbd_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <package/prefixdb_package.hpp>

int main(int argc, char* argv[])
{
  return wfc::wfc<prefixdbd_build_info>(wfc::wfcroot(
    {
      std::make_shared<wamba::prefixdb_package>()
    }
  )).run(argc, argv,
    "PrefixDB демон на базе платформы WFC и модуля wfc_prefixdb, предоставляет \n"
    "jsonrpc-интерфейс к rocksdb. Список просмотра списка дополнительных опций: ./prefixdbd --info wfc_prefixdb "
  );
}
