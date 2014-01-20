include(BuildInfo)

include_directories(../wfc)
include_directories(../wfc_startup)
include_directories(../wfc_config)
include_directories(../wfc_core)
include_directories(../wfc_logger)
include_directories(../wfc_hub)
include_directories(../wfc_leveldb)
include_directories(../leveldb)

add_executable(leveldb leveldb.cpp)

#find_library(COMET NAMES comet PATHS ../../comet/build/comet NO_DEFAULT_PATH)

#message(STATUS ${COMET} )

target_link_libraries(leveldb wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub)
add_dependencies(leveldb wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub)
build_info(leveldb leveldb)
