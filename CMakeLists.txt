cmake_minimum_required(VERSION 3.0.1)

project(prefixdbd)

include(ci.cmake)

wfcroot(rocksdb wfc_prefixdb)

add_subdirectory(daemon)
