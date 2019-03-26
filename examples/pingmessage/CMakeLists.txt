# Name the application after the directory it is in
get_filename_component(AppName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" AppName ${AppName})

add_executable(${AppName}
  ${AppName}.cpp
  )

target_link_libraries( ${AppName}
  blueping
  )

