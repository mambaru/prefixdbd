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

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/master7/prefixdb.conf )
  add_test(
    NAME prefixdb.conf
    COMMAND prefixdbd --check-config=configurations/master7/prefixdb.conf 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/master7/prefixdb-load.conf )
  add_test(
    NAME prefixdb-load.conf
    COMMAND prefixdbd --check-config=configurations/master7/prefixdb-load.conf 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()
