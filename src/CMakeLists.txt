
set (LIB_NAME blueping)


file(GLOB SRC *.cpp *.h)
add_library( ${LIB_NAME} SHARED ${SRC})

target_include_directories(${LIB_NAME} INTERFACE)
