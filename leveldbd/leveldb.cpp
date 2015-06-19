#include "demod_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <wfc_demo/demo/demo_package.hpp>

int main(int argc, char* argv[])
{
  return ::wfc::wfc(
    ::wfc::make_build_info<demod_build_info>(), 
    ::wfc::wfcroot({
    })
  ).run(argc, argv);
}
