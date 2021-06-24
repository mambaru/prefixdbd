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

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/prefixdb.conf )
  add_test(
    NAME prefixdb.conf
    COMMAND prefixdbd --check-config=configurations/prefixdb.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/master.conf )
  add_test(
    NAME master.conf
    COMMAND prefixdbd --check-config=configurations/master.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/slave.conf )
  add_test(
    NAME slave.conf
    COMMAND prefixdbd --check-config=configurations/slave.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/slave5/slave.conf )
  add_test(
    NAME slave5/slave.conf
    COMMAND prefixdbd --check-config=configurations/slave5/slave.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()

if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations/master-slave.conf )
  add_test(
    NAME master-slave.conf
    COMMAND prefixdbd --check-config=configurations/master-slave.conf
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()
