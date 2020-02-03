cmake_minimum_required(VERSION 3.1)

project(prefixdbd)

include(cmake/ci.cmake)

wci_getlib(NAME wfcroot SUPERMODULE)
wci_getlib(NAME wfc_prefixdb)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
  if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations)
    add_subdirectory(configurations)
  endif()
endif()
