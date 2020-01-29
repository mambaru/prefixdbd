
add_test(
  NAME prefixdb.conf
  COMMAND prefixdbd --check-config=configurations/production/prefixdb.conf 
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_test(
  NAME master7.conf
  COMMAND prefixdbd --check-config=configurations/master7/master7.conf 
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_test(
  NAME master7-load.conf
  COMMAND prefixdbd --check-config=configurations/master7/master7-load.conf 
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
