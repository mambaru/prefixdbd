cmake_minimum_required(VERSION 2.6)
project(wfc_repli-hub-test)

enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/../wfc/cmake;${CMAKE_SOURCE_DIR}/../../wfc/cmake")

include(Wfc)

include_directories(../repli_client)
include_directories(../wfc)
include_directories(../../wfc)

add_executable(repli_client_test repli_client_test.cpp ../repli_hub/hub/repli_client.cpp )
add_executable(repli_channel_test repli_channel_test.cpp ../repli_hub/hub/repli_client.cpp )

target_link_libraries(repli_client_test pthread wfc )
target_link_libraries(repli_channel_test pthread wfc )

add_test(repli_client_test repli_client_test)
add_test(repli_channel_test repli_channel_test)
