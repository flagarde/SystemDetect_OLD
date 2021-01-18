#pragma once

namespace SystemDetect
{
  static const char* getArchitecture(){ return "@ARCH@"; }
  static const char* getBaseArchitecture(){ return "@BASEARCH@"; }
  static const char* getSystem(){ return "@CMAKE_SYSTEM_NAME@"; }
  static const char* getCCompiler(){ return "@CMAKE_C_COMPILER_ID@"; }
  static const char* getCXXCompiler(){ return "@CMAKE_CXX_COMPILER_ID@"; }
  static const char* getCCompilerVersion(){ return "@CMAKE_C_COMPILER_VERSION@"; }
  static const char* getCXXCompilerVersion(){ return "@CMAKE_CXX_COMPILER_VERSION@"; }
  static const int getCCompilerMajorVersion(){ return @C_COMPILER_VERSION_MAJOR@; }
  static const int getCCompilerMinorVersion(){ return @C_COMPILER_VERSION_MINOR@; }
  static const int getCCompilerPatchVersion(){ return @C_COMPILER_VERSION_PATCH@; }
  static const int getCXXCompilerMajorVersion(){ return @CXX_COMPILER_VERSION_MAJOR@; }
  static const int getCXXCompilerMinorVersion(){ return @CXX_COMPILER_VERSION_MINOR@; }
  static const int getCXXCompilerPatchVersion(){ return @CXX_COMPILER_VERSION_PATCH@; }
  static const bool isBigEndian(){ return @ENDIANNESS@; }
  static const bool isLittleEndian() {return !@ENDIANNESS@; }
  static const char* getEndianness()
  {
      if(isBigEndian()) return "BigEndian";
      else return "LittleEndian";
  }
}
