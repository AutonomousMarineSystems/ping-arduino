cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(ProjectName ping-linux )

# Credit where it is due:
# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  -Wpedantic -Wall -Wextra")
#TODO Make these set-able sometime
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

#Include generated protobuf output
include_directories(
  src
  ${CMAKE_BINARY_DIR}/src/protobuf
  )

enable_testing()

add_subdirectory(src)
add_subdirectory(examples)


