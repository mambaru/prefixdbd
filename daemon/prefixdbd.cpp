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
  )).run(argc, argv,
    "PrefixDB демон на базе платформы WFC и модуля wfc_prefixdb, который обеспечивает\n"
    "jsonrpc-интерфейс к rocksdb определенного формата (строка+метаданые). Для модуля\n"
    "доступны следующие опции:\n"
    "  export=<<path>> - преобразование баз в формат где все значения строчки\n"
    "  import=<<path>> - преобразование баз в формат где все значения строчки"
  );
}
