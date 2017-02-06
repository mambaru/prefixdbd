cmake_minimum_required(VERSION 2.6)

project(prefixdbd)

# set(CMAKE_SKIP_RPATH ON)

if ( NOT WFC_READY )
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake")
  include(Wfc)
endif()

# lua
add_subdirectory(luajit-2.0)
link_directories(${CMAKE_SOURCE_DIR}/luajit-2.0/src)
include_directories(${CMAKE_SOURCE_DIR}/luajit-2.0/src)

# facebook-rocksdb
add_custom_target( 
  facebook-rocksdb
  COMMAND make shared_lib
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/facebook-rocksdb
  VERBATIM
)
link_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb)
include_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb)
include_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb/include)

include_directories(${CMAKE_SOURCE_DIR}/wfc_prefixdb/package)


add_subdirectory(daemon)
add_subdirectory(wfc_prefixdb)
add_subdirectory(wfcroot)
