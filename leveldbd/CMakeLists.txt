include(BuildInfo)

include_directories(../wfc)
include_directories(../wfc_startup)
include_directories(../wfc_config)
include_directories(../wfc_core)
include_directories(../wfc_logger)
include_directories(../wfc_hub)
include_directories(../wfc_leveldb)
#include_directories(../leveldb)

add_executable(leveldbd leveldb.cpp)

#find_library(COMET NAMES comet PATHS ../../comet/build/comet NO_DEFAULT_PATH)

#message(STATUS ${COMET} )

target_link_libraries(leveldbd wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub wfc_leveldb leveldb_storage pthread)
add_dependencies(leveldbd wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub wfc_leveldb leveldb_storage)
build_info(leveldbd leveldbd)
