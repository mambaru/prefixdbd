cmake_minimum_required(VERSION 3.1)

project(prefixdbd)

include(cmake/ci.cmake)

wci_submodule(NAME wfcroot SUPERMODULE)
wci_submodule(NAME wfc_prefixdb)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()
