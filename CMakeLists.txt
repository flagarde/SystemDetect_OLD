cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(SystemDetect VERSION "0.9.0.0" DESCRIPTION "Detect system architecture etc.." HOMEPAGE_URL "https://github.com/flagarde/SystemDetect" LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_EXAMPLES "Build the examples" ON)
option(BUILD_TESTS "Build the tests" ON)

include(detect-arch)
include(detect-compiler)
include(detect-endianness)

configure_file("${CMAKE_CURRENT_LIST_DIR}/cmake/SystemDetectMacro.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/SystemDetect/SystemDetectMacro.hpp" @ONLY)
configure_file("${CMAKE_CURRENT_LIST_DIR}/cmake/SystemDetect.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/SystemDetect/SystemDetect.hpp" @ONLY)

add_library(SystemDetect INTERFACE)
target_include_directories(SystemDetect INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/SystemDetect> $<INSTALL_INTERFACE:include/SystemDetect>)
set_target_properties(SystemDetect PROPERTIES PUBLIC_HEADER "include/DisableWarning.hpp")
add_library(SystemDetect::SystemDetect ALIAS SystemDetect)
install(TARGETS SystemDetect  EXPORT SystemDetect RUNTIME DESTINATION bin LIBRARY DESTINATION ${LIBRARY_OUTPUT_DIR} ARCHIVE DESTINATION ${ARCHIVE_OUTPUT_DIR} PUBLIC_HEADER DESTINATION "include/SystemDetect")
install(EXPORT SystemDetect FILE "SystemDetect.cmake" DESTINATION "lib/cmake/SystemDetect" NAMESPACE SystemDetect::)
include(CMakePackageConfigHelpers)
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/SystemDetectConfigVersion.cmake" VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/SystemDetectConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/SystemDetectConfig.cmake" INSTALL_DESTINATION "lib/cmake/SystemDetect"  PATH_VARS CMAKE_INSTALL_PREFIX)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/SystemDetectConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/SystemDetectConfigVersion.cmake"  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/detect-arch.cmake" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/detect-compiler.cmake" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/detect-endianness.cmake" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/detect-arch.c" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SystemDetectMacro.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SystemDetect.hpp.in" DESTINATION "lib/cmake/SystemDetect/")

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
