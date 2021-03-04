if(CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
  set(SYSTEMDETECT_C_COMPILER_ID "Apple")
else()
  set(SYSTEMDETECT_C_COMPILER_ID "${CMAKE_C_COMPILER_ID}")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  set(SYSTEMDETECT_CXX_COMPILER_ID "Apple")
else()
  set(SYSTEMDETECT_CXX_COMPILER_ID "${CMAKE_CXX_COMPILER_ID}")
endif()

message(STATUS "${SYSTEMDETECT_CXX_COMPILER_ID}")
message(STATUS "${SYSTEMDETECT_C_COMPILER_ID}")

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

#MSVC seems to not propagate the C version
if(DEFINED CMAKE_CXX_COMPILER_VERSION AND MSVC)
  set(C_COMPILER_VERSION_MAJOR "${CXX_COMPILER_VERSION_MAJOR}")
  set(C_COMPILER_VERSION_MINOR "${CXX_COMPILER_VERSION_MINOR}")
  set(C_COMPILER_VERSION_PATCH "${CXX_COMPILER_VERSION_PATCH}")
endif()
