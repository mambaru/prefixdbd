cmake_minimum_required(VERSION 3.0.1)

project(prefixdbd)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake" "${CMAKE_SOURCE_DIR}/cmake")
#include(Wfc)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ci)

# https://github.com/facebook/rocksdb/blob/d1b26507bd97791437d870665277b55eb9e7ce95/INSTALL.md
# zlib - a library for data compression.
# bzip2 - a library for data compression.
# lz4 - a library for extremely fast data compression.
# snappy - a library for fast data compression.
# zstandard - Fast real-time compression algorithm.

if ( NOT IGNORE_COMPRESS_LIBS )
  message(STATUS "Use IGNORE_COMPRESS_LIBS=ON for disable 'REQUIRED' for compression library")
  find_package(Snappy REQUIRED)
  find_package(ZLIB REQUIRED)
  find_package(BZip2 REQUIRED)
  find_package(LZ4 REQUIRED)
  find_package(ZSTD REQUIRED)
endif()

if ( BUILD_SHARED_LIBS )
  set(shared_lib "shared_lib")
else()
  set(shared_lib "static_lib")
endif()

message(STATUS "shared_lib=${shared_lib}")
add_custom_target( 
  facebook-rocksdb
  COMMAND make USE_RTTI=1 ${shared_lib}
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/facebook-rocksdb
  VERBATIM
)
link_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb)
include_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb)
include_directories(${CMAKE_SOURCE_DIR}/facebook-rocksdb/include)
include_directories(${CMAKE_SOURCE_DIR}/wfc_prefixdb/package)

add_subdirectory(wfcroot)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake)
include(Wfc)

add_subdirectory(wfc_prefixdb)
add_subdirectory(daemon)



