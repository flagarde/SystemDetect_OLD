cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(SystemDetectTest VERSION "0.9.0.0" DESCRIPTION "Test SystemDetect" HOMEPAGE_URL "https://github.com/flagarde/SystemDetect" LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" "${SYSTEM_DETECT_PATH}")

message(STATUS "${CMAKE_BINARY_DIR}")

add_executable(TestSystemDetect2 SystemDetect.cpp)
target_link_libraries(TestSystemDetect2 PRIVATE SystemDetect::SystemDetect)
install(TARGETS TestSystemDetect2 RUNTIME DESTINATION "bin/tests")

add_test(NAME TestSystemDetect2 COMMAND TestSystemDetect2)
