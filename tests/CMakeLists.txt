cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(SystemDetectTest VERSION "0.9.0.0" DESCRIPTION "Test SystemDetect" HOMEPAGE_URL "https://github.com/flagarde/SystemDetect" LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" "${SYSTEM_DETECT_PATH}")

message(STATUS "${CMAKE_BINARY_DIR}")

add_executable(Test Test.cpp)
target_link_libraries(Test PRIVATE SystemDetect::SystemDetect)
target_compile_definitions(Test PUBLIC ${TEST_SYSTEM} PUBLIC ${TEST_ARCH} PUBLIC ${TEST_COMPILER})
install(TARGETS Test RUNTIME DESTINATION "bin/tests")
add_test(NAME Test COMMAND Test )
