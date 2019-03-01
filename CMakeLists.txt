cmake_minimum_required(VERSION 3.0.1)

project(prefixdbd)

include(cmake/ci.cmake)
include(external/cmake-ci/cmake/rocksdb.cmake)
wfcroot(wfc_prefixdb)
get_rocksdb()

add_subdirectory(daemon)
