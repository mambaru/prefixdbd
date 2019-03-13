cmake_minimum_required(VERSION 3.1)

project(prefixdbd)

include(cmake/ci.cmake)
include(rocksdb)

get_rocksdb()
wfcroot(wfc_prefixdb)

add_subdirectory(daemon)
