
add_test(
  NAME prefixdb.conf
  COMMAND prefixdbd --check-config=configurations/production/prefixdb.conf 
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
