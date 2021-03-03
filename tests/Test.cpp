#include "SystemDetectMacro.hpp"

#include <iostream>
#include <string>

int main() {

#if ARCHITECTURE_IS(TEST_ARCH)
  std::cout << "I guessed the right architecture : "+std::string(TEST_ARCH) << std::endl;
#else
  #error Wrong Architecture
#endif

#if SYSTEM_IS(TEST_SYSTEM)
  std::cout << "I guessed the right system : "+std::string(TEST_ARCH) << std::endl;
#else
  #error Wrong System
#endif

#if C_COMPILER_IS(TEST_COMPILER)
  std::cout << "I guessed the right C compiler : "+std::string(TEST_COMPILER) << std::endl;
#else
  #error Wrong Compiler
#endif

  return 0;
}
