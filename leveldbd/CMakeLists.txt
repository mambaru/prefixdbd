include(BuildInfo)

include_directories(..)

add_executable(leveldbd leveldbd.cpp )

SET(
  leveldbd_lib_list
    wfcroot
    wfc_leveldbd
)

target_link_libraries(leveldbd ${leveldbd_lib_list})

add_dependencies(leveldbd ${leveldbd_lib_list})

build_info(leveldbd leveldbd)

install(TARGETS leveldbd DESTINATION ${CMAKE_INSTALL_PREFIX})
