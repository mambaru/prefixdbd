if ( EXISTS ${CMAKE_SOURCE_DIR}/examples/example01.conf )
  add_test(
    NAME example01.conf
    COMMAND prefixdbd --check-config=examples/example01.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/examples/example01-slave.conf )
  add_test(
    NAME example01-slave.conf
    COMMAND prefixdbd --check-config=examples/example01-slave.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()
