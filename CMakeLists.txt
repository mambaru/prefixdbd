cmake_minimum_required(VERSION 2.6)

project(leveldbd)

if ( NOT WFC_READY )
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake")
  include(Wfc)
endif()

include_directories(faslib)
include_directories(wfcroot/wfc)
include_directories(wfcroot/iow)

add_subdirectory(faslib)
add_subdirectory(wfcroot)
add_subdirectory(wfc_leveldb)
add_subdirectory(leveldbd)

