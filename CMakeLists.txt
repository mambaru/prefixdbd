cmake_minimum_required(VERSION 2.6)

project(leveldbd)

if ( NOT WFC_READY )
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake")
  include(Wfc)
endif()

# lua
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/luajit-2.0/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/luajit-2.0/src)

# google-leveldb
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/google-leveldb)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/google-leveldb/include)

include_directories(wfc_leveldb)
include_directories(wfc_prefixdb)

add_subdirectory(luajit-2.0)
add_subdirectory(google-leveldb)
add_subdirectory(wfcroot)
add_subdirectory(wfc_leveldb)
add_subdirectory(wfc_prefixdb)
add_subdirectory(leveldbd)
