cmake_minimum_required(VERSION 2.6)

project(wfc_repli-hub)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/wfc/cmake;${CMAKE_SOURCE_DIR}/../wfc/cmake")

include(Wfc)

include_directories(.)
include_directories(wfc)
include_directories(../wfc)

add_subdirectory(repli_hub)
add_subdirectory(tests)

