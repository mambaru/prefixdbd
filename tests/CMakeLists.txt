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

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/mastern5/prefixdb.conf )
  add_test(
    NAME mastern5
    COMMAND prefixdbd --check-config=configurations/mastern5/prefixdb.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/mastern5/prefixdb-load.conf )
  add_test(
    NAME mastern5-load.conf
    COMMAND prefixdbd --check-config=configurations/mastern5/prefixdb-load.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/mastern5/second-master.conf )
  add_test(
    NAME mastern5-second.conf
    COMMAND prefixdbd --check-config=configurations/mastern5/second-master.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/mastern7/prefixdb.conf )
  add_test(
    NAME mastern7
    COMMAND prefixdbd --check-config=configurations/mastern7/prefixdb.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/mastern7/prefixdb-load.conf )
  add_test(
    NAME mastern7-load
    COMMAND prefixdbd --check-config=configurations/mastern7/prefixdb-load.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()
