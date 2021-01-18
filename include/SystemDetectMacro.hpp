#pragma once

#define SYSTEMDETECT_@ARCH@ 1
#define ARCHITECTURE_IS(ARCH)( SYSTEMDETECT_##ARCH == SYSTEMDETECT_@ARCH@ )
#undef  SYSTEMDETECT_@ARCH@

#define SYSTEMDETECT_@BASEARCH@ 1
#define BASE_ARCHITECTURE_IS(BASE_ARCH)( SYSTEMDETECT_##BASE_ARCH == SYSTEMDETECT_@BASEARCH@ )
#undef  SYSTEMDETECT_@BASEARCH@

#define SYSTEMDETECT_@CMAKE_SYSTEM_NAME@ 1
#define SYSTEM_IS(SYSTEM)( SYSTEMDETECT_##SYSTEM == SYSTEMDETECT_@CMAKE_SYSTEM_NAME@ )
#undef  SYSTEMDETECT_@CMAKE_SYSTEM_NAME@

#define SYSTEMDETECT_@CMAKE_C_COMPILER_ID@ 1
#define C_COMPILER_IS(C_COMPILER)( SYSTEMDETECT_##C_COMPILER == SYSTEMDETECT_@CMAKE_C_COMPILER_ID@ )
#undef SYSTEMDETECT_@CMAKE_C_COMPILER_ID@

#define SYSTEMDETECT_@CMAKE_CXX_COMPILER_ID@ 1
#define CXX_COMPILER_IS(CXX_COMPILER)( SYSTEMDETECT_##CXX_COMPILER == SYSTEMDETECT_@CMAKE_CXX_COMPILER_ID@ )
#undef SYSTEMDETECT_@CMAKE_CXX_COMPILER_ID@

#define SYSTEMDETECT_C_COMPILER_VERSION_MAJOR @C_COMPILER_VERSION_MAJOR@
#define SYSTEMDETECT_C_COMPILER_VERSION_MINOR @C_COMPILER_VERSION_MINOR@
#define SYSTEMDETECT_C_COMPILER_VERSION_PATCH @C_COMPILER_VERSION_PATH@
#define C_COMPILER_MAJOR_MINOR_VERSION(MAJOR,MINOR)( MAJOR == @C_COMPILER_VERSION_MAJOR@ and MINOR == @C_COMPILER_VERSION_MINOR@ )
#define C_COMPILER_MAJOR_MINOR_PATCH_VERSION(MAJOR,MINOR,PATCH)( MAJOR == @C_COMPILER_VERSION_MAJOR@ and MINOR == @C_COMPILER_VERSION_MINOR@ and PATCH == @C_COMPILER_VERSION_PATH@ )
#define C_COMPILER_MAJOR_VERSION(MAJOR)( MAJOR == SYSTEMDETECT_C_COMPILER_VERSION_MAJOR )
#define C_COMPILER_MINOR_VERSION(MINOR)( MINOR == SYSTEMDETECT_C_COMPILER_VERSION_MINOR )
#define C_COMPILER_PATCH_VERSION(PATCH)( PATCH == SYSTEMDETECT_C_COMPILER_VERSION_PATCH )
#undef SYSTEMDETECT_C_COMPILER_VERSION_MAJOR
#undef SYSTEMDETECT_C_COMPILER_VERSION_MINOR
#undef SYSTEMDETECT_C_COMPILER_VERSION_PATCH

#define SYSTEMDETECT_CXX_COMPILER_VERSION_MAJOR @CXX_COMPILER_VERSION_MAJOR@
#define SYSTEMDETECT_CXX_COMPILER_VERSION_MINOR @CXX_COMPILER_VERSION_MINOR@
#define SYSTEMDETECT_CXX_COMPILER_VERSION_PATCH @CXX_COMPILER_VERSION_PATH@
#define CXX_COMPILER_MAJOR_MINOR_VERSION(MAJOR,MINOR)( MAJOR == @CXX_COMPILER_VERSION_MAJOR@ and MINOR == @CXX_COMPILER_VERSION_MINOR@ )
#define CXX_COMPILER_MAJOR_MINOR_PATCH_VERSION(MAJOR,MINOR,PATCH)( MAJOR == @CXX_COMPILER_VERSION_MAJOR@ and MINOR == @CXX_COMPILER_VERSION_MINOR@ and PATCH == @CXX_COMPILER_VERSION_PATH@ )
#define CXX_COMPILER_MAJOR_VERSION(MAJOR)( MAJOR == SYSTEMDETECT_CXX_COMPILER_VERSION_MAJOR )
#define CXX_COMPILER_MINOR_VERSION(MINOR)( MINOR == SYSTEMDETECT_CXX_COMPILER_VERSION_MINOR )
#define CXX_COMPILER_PATCH_VERSION(PATCH)( PATCH == SYSTEMDETECT_CXX_COMPILER_VERSION_PATCH )
#undef SYSTEMDETECT_CXX_COMPILER_VERSION_MAJOR
#undef SYSTEMDETECT_CXX_COMPILER_VERSION_MINOR
#undef SYSTEMDETECT_CXX_COMPILER_VERSION_PATCH
