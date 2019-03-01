cmake_minimum_required(VERSION 3.0.1)

project(prefixdbd)

include(cmake/ci.cmake)
include(external/cmake-ci/cmake/rocksdb.cmake)

get_rocksdb()
wfcroot(wfc_prefixdb)


add_subdirectory(daemon)
