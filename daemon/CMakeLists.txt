include(BuildInfo)

include_directories(..)

add_executable(prefixdbd prefixdbd.cpp )

SET(
  prefixdbd_lib_list
  wfc_prefixdb
  wfcroot
)

target_link_libraries(prefixdbd ${prefixdbd_lib_list}  )

add_dependencies(prefixdbd ${prefixdbd_lib_list})

build_info(prefixdbd prefixdbd)

install(TARGETS prefixdbd DESTINATION ${CMAKE_INSTALL_PREFIX})

