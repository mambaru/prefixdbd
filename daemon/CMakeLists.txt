add_executable(prefixdbd prefixdbd.cpp )
target_link_libraries(prefixdbd PRIVATE wfc_prefixdb wfcroot)
wci_targets(prefixdbd)

add_dependencies(prefixdbd wfc_prefixdb wfcroot)

build_info(prefixdbd prefixdbd)

install(TARGETS prefixdbd DESTINATION ${CMAKE_INSTALL_PREFIX})

