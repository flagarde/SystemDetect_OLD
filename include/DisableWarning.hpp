#pragma once

#include "SystemDetectMacro.hpp"

// clang-format off

#if C_COMPILER_IS(MSVC) || CXX_COMPILER_IS(MSVC)
  #define DISABLE_WARNING_PUSH           __pragma(warning( push ))
  #define DISABLE_WARNING_POP            __pragma(warning( pop ))
  #define DISABLE_WARNING(warningNumber) __pragma(warning( disable :  warningNumber))
#elif C_COMPILER_IS(Clang) || CXX_COMPILER_IS(Clang)
  #define DO_PRAGMA(X) _Pragma(#X)
  #define DISABLE_WARNING_PUSH           DO_PRAGMA(clang diagnostic push)
  #define DISABLE_WARNING_POP            DO_PRAGMA(clang diagnostic pop)
  #define DISABLE_WARNING(warningName)   DO_PRAGMA(clang diagnostic ignored #warningName)
  #undef DO_PRAGMA
#elif C_COMPILER_IS(GNU) || CXX_COMPILER_IS(GNU)
  #define DO_PRAGMA(X) _Pragma(#X)
  #define DISABLE_WARNING_PUSH           DO_PRAGMA(GCC diagnostic push)
  #define DISABLE_WARNING_POP            DO_PRAGMA(GCC diagnostic pop)
  #define DISABLE_WARNING(warningName)   DO_PRAGMA(GCC diagnostic ignored #warningName)
  #undef DO_PRAGMA
#else
  #define DISABLE_WARNING_PUSH
  #define DISABLE_WARNING_POP
#endif

// clang-format on
