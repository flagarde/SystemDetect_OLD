#include "SystemDetect.hpp"
#include "SystemDetectMacro.hpp"

#include <iostream>

int main()
{
  std::cout << "System : " << SystemDetect::getSystem() << std::endl;
  std::cout << "Architecture : " << SystemDetect::getArchitecture() << std::endl;
  std::cout << "Base architecture : " << SystemDetect::getBaseArchitecture() << std::endl;
  std::cout << "C compiler : " << SystemDetect::getCCompiler() << std::endl;
  std::cout << "C compiler version : " << SystemDetect::getCCompilerVersion() << std::endl;
  std::cout << "C compiler major : " << SystemDetect::getCCompilerMajorVersion() << std::endl;
  std::cout << "C compiler minor : " << SystemDetect::getCCompilerMinorVersion() << std::endl;
  std::cout << "C compiler patch : " << SystemDetect::getCCompilerPatchVersion() << std::endl;
  std::cout << "CXX compiler : " << SystemDetect::getCXXCompiler() << std::endl;
  std::cout << "CXX compiler version : " << SystemDetect::getCXXCompilerVersion() << std::endl;
  std::cout << "CXX compiler major : " << SystemDetect::getCXXCompilerMajorVersion() << std::endl;
  std::cout << "CXX compiler minor : " << SystemDetect::getCXXCompilerMinorVersion() << std::endl;
  std::cout << "CXX compiler patch : " << SystemDetect::getCXXCompilerPatchVersion() << std::endl;
  std::cout << "Endianness : " << SystemDetect::getEndianness() << std::endl;
  std::cout << "Is bigendian : " << SystemDetect::isBigEndian() << std::endl;
  std::cout << "Is littleendian : " << SystemDetect::isLittleEndian() << std::endl;

#if defined(Clang)
  #if C_COMPILER_IS(Clang)
  std::cout << "I guessed the right architecture : Clang" << std::endl;
  #else
    #error Wrong compiler
  #endif
#elif defined(GNU)
  #if C_COMPILER_IS(GNU)
  std::cout << "I guessed the right architecture : GNU" << std::endl;
  #else
    #error Wrong compiler
  #endif
#elif defined(MSVC)
  #if C_COMPILER_IS(MSVC)
  std::cout << "I guessed the right architecture : MSVC" << std::endl;
  #else
    #error Wrong compiler
  #endif
#endif

#if defined(Linux)
  #if SYSTEM_IS(Linux)
  std::cout << "I guessed the right system : Linux" << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(Darwin)
  #if SYSTEM_IS(Darwin)
  std::cout << "I guessed the right system : Darwin" << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(Windows)
  #if SYSTEM_IS(Windows)
  std::cout << "I guessed the right system : Windows" << std::endl;
  #else
    #error Wrong system
  #endif
#endif

#if defined(x86_64)
  #if ARCHITECTURE_IS(x86_64)
  std::cout << "I guessed the right architectures : x86_64" << std::endl;
  #else
    #error Wrong arch
  #endif
#elif defined(x86)
  #if ARCHITECTURE_IS(x86)
  std::cout << "I guessed the right architectures : x86" << std::endl;
  #else
    #error Wrong arch
  #endif
#endif

  return 0;
}
