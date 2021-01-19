include(detect-arch)
include(detect-compiler)
include(detect-endianness)

configure_file("${CMAKE_CURRENT_LIST_DIR}/../cmake/SystemDetectMacro.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/../SystemDetect/SystemDetectMacro.hpp" @ONLY)
configure_file("${CMAKE_CURRENT_LIST_DIR}/../cmake/SystemDetect.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/../SystemDetect/SystemDetect.hpp" @ONLY)

add_executable(TestSystemDetect SystemDetect.cpp)
target_link_libraries(TestSystemDetect PRIVATE SystemDetect::SystemDetect)

add_executable(TestSystemDetectMacro SystemDetectMacro.cpp)
target_link_libraries(TestSystemDetectMacro PRIVATE SystemDetect::SystemDetect)

install(TARGETS TestSystemDetect TestSystemDetectMacro RUNTIME DESTINATION bin)

add_test(NAME TestSystemDetect COMMAND TestSystemDetect)
add_test(NAME TestSystemDetectMacro COMMAND TestSystemDetectMacro)
