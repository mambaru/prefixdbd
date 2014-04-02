message(STATUS "MODULE PATH: ${CMAKE_MODULE_PATH}")


include(BuildInfo)

SET(
  wfc_repli_hub_source_list
  hub/repli_hub.cpp  
  hub/repli_client.cpp  
  repli_hub_instance.cpp
)

add_library(
  wfc_repli-hub SHARED
  ${wfc_repli_hub_source_list}
)

build_info(wfc_repli-hub repli_hub)

