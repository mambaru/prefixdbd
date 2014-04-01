cmake_minimum_required(VERSION 2.6)

project(leveldb)

include_directories(wfc)
include_directories(faslib)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfc/cmake")

add_subdirectory(faslib)
add_subdirectory(wfc)
add_subdirectory(wfc_startup)
add_subdirectory(wfc_core)
add_subdirectory(wfc_config)
add_subdirectory(wfc_logger)
add_subdirectory(wfc_hub)
add_subdirectory(wfc_leveldb)
add_subdirectory(wfc_pubsub-service)
add_subdirectory(wfc_pubsub-gateway)
add_subdirectory(leveldbd)

