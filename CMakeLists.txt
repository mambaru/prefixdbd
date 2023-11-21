cmake_minimum_required(VERSION 3.10)

#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#set(BUILD_SHARED_LIBS OFF)
#set(CMAKE_EXE_LINKER_FLAGS "-static")

project(prefixdbd)

include(cmake/ci.cmake)

wci_submodule(NAME wfcroot SUPERMODULE)
wci_submodule(NAME wfc_prefixdb)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()
