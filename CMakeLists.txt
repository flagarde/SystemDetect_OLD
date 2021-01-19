cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(SystemDetect VERSION "0.9.0.0" DESCRIPTION "Detect system architecture etc.." HOMEPAGE_URL "https://github.com/flagarde/SystemDetect" LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build the tests" ON)

include(detect-arch)

if(DEFINED CMAKE_C_COMPILER_VERSION)
  string(REPLACE "." ";" C_COMPILER_VERSION ${CMAKE_C_COMPILER_VERSION})
  list(GET C_COMPILER_VERSION 0 C_COMPILER_VERSION_MAJOR)
  list(GET C_COMPILER_VERSION 1 C_COMPILER_VERSION_MINOR)
  list(GET C_COMPILER_VERSION 2 C_COMPILER_VERSION_PATCH)
else()
  set(C_COMPILER_VERSION_MAJOR "-1")
  set(C_COMPILER_VERSION_MINOR "-1")
  set(C_COMPILER_VERSION_PATCH "-1")
endif()

if(DEFINED CMAKE_CXX_COMPILER_VERSION)
  string(REPLACE "." ";" CXX_COMPILER_VERSION ${CMAKE_CXX_COMPILER_VERSION})
  list(GET CXX_COMPILER_VERSION 0 CXX_COMPILER_VERSION_MAJOR)
  list(GET CXX_COMPILER_VERSION 1 CXX_COMPILER_VERSION_MINOR)
  list(GET CXX_COMPILER_VERSION 2 CXX_COMPILER_VERSION_PATCH)
else()
  set(CXX_COMPILER_VERSION_MAJOR "-1")
  set(CXX_COMPILER_VERSION_MINOR "-1")
  set(CXX_COMPILER_VERSION_PATCH "-1")
endif()

include(TestBigEndian)
test_big_endian(ENDIANNESS)

configure_file(include/SystemDetectMacro.hpp "${CMAKE_CURRENT_BINARY_DIR}" @ONLY)
configure_file(include/SystemDetect.hpp "${CMAKE_CURRENT_BINARY_DIR}" @ONLY)

add_library(SystemDetect INTERFACE)
target_include_directories(SystemDetect
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
                                     $<INSTALL_INTERFACE:include/SystemDetect>)

if(BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
