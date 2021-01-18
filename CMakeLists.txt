cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(SystemDetect VERSION "0.9.0.0" DESCRIPTION "Detect system architecture etc.." HOMEPAGE_URL "https://github.com/flagarde/SystemDetect" LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build the tests" ON)

include(detect-arch)

configure_file(include/SystemDetect.hpp "${CMAKE_CURRENT_BINARY_DIR}" @ONLY)

add_library(SystemDetect INTERFACE)
target_include_directories(SystemDetect 
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
                                     $<INSTALL_INTERFACE:include/SystemDetect>)

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
