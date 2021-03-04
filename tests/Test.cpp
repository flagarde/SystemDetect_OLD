#include "SystemDetectMacro.hpp"

#include <iostream>
#include <string>

int main() {

#if defined(Clang)
  #if C_COMPILER_IS(Clang)
  std::cout << "I guessed the right architecture : Clang" << std::endl;
  #else
    #error Wrong architecture
  #endif
#elif defined(GNU)
  #if C_COMPILER_IS(GNU)
    std::cout << "I guessed the right architecture : GNU" << std::endl;
  #else
    #error Wrong architecture
  #endif
#elif defined(MSVC)
  #if C_COMPILER_IS(MSVC)
    std::cout << "I guessed the right architecture : MSVC" << std::endl;
  #else
    #error Wrong architecture
  #endif
#endif

#if defined(Linux)
  #if SYSTEM_IS(Linux)
    std::cout << "I guessed the right system : Linux" << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(MacOS)
  #if SYSTEM_IS(MacOS)
    std::cout << "I guessed the right system : MacOS" << std::endl;
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
    #error Wrong system
  #endif
#elif defined(x86)
  #if ARCHITECTURE_IS(x86)
    std::cout << "I guessed the right architectures : x86" << std::endl;
  #else
    #error Wrong system
  #endif
#endif

  return 0;
}
