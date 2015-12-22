cmake_minimum_required(VERSION 2.6)

project(leveldbd)

#set(CMAKE_CXX_COMPILER g++-4.8)

if ( NOT WFC_READY )
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake")
  include(Wfc)
endif()

# lua
add_subdirectory(luajit-2.0)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/luajit-2.0/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/luajit-2.0/src)

# google-leveldb
add_subdirectory(google-leveldb)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/google-leveldb)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/google-leveldb/include)

# facebook-rocksdb

#add_subdirectory(rocksdb)

add_custom_target( 
  facebook-rocksdb
  COMMAND make CXX=g++-4.8 shared_lib
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/rocksdb
  VERBATIM
)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/rocksdb)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/rocksdb/include)


include_directories(wfc_leveldb)
include_directories(wfc_prefixdb)

add_subdirectory(wfcroot)
add_subdirectory(wfc_leveldb)
add_subdirectory(wfc_prefixdb)
add_subdirectory(leveldbd)
