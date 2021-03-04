#include "SystemDetectMacro.hpp"

#include <iostream>
#include <string>

int main() {

#if defined(Clang)
  #if TEST_COMPILER(Clang2)
    std::cout << "I guessed the right architecture : "+std::string(Clang) << std::endl;
  #else
    #error Wrong architecture
  #endif
#elif defined(GNU)
  #if TEST_COMPILER(GNU)
    std::cout << "I guessed the right architecture : "+std::string(GNU) << std::endl;
  #else
    #error Wrong architecture
  #endif
#elif defined(MSVC)
    #if TEST_COMPILER(MSVC)
    std::cout << "I guessed the right architecture : "+std::string(MSVC) << std::endl;
  #else
    #error Wrong architecture
  #endif
#endif

#if defined(Linux)
  #if TEST_SYSTEM(Linux)
    std::cout << "I guessed the right system : "+std::string(Linux) << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(MacOS)
  #if TEST_SYSTEM(MacOS)
    std::cout << "I guessed the right system : "+std::string(MacOS) << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(Windows)
  #if TEST_SYSTEM(Windows)
    std::cout << "I guessed the right system : "+std::string(Windows) << std::endl;
  #else
    #error Wrong system
  #endif
#endif


#if defined(X86_64)
  #if TEST_ARCH(X86_64)
    std::cout << "I guessed the right architectures : "+std::string(X86_64) << std::endl;
  #else
    #error Wrong system
  #endif
#elif defined(X86)
  #if TEST_ARCH(X86)
    std::cout << "I guessed the right architectures : "+std::string(X86) << std::endl;
  #else
    #error Wrong system
  #endif
#endif

  return 0;
}
