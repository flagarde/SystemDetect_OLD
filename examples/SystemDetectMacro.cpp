#include "SystemDetectMacro.hpp"

#include <iostream>

int main() {
#if ARCHITECTURE_IS(x86_64)
  std::cout << "x86_64" << std::endl;
#else
  std::cout << "Is not x86_64" << std::endl;
#endif

#if CXX_COMPILER_MAJOR_VERSION(10) && CXX_COMPILER_MINOR_VERSION(2)
  std::cout << "Compiler version is 10.2" << std::endl;
#else
  std::cout << "Compiler version is not 10.2" << std::endl;
#endif

#if IS_BIG_ENDIAN
  std::cout << "Is big endian" << std::endl;
#endif

#if IS_LITTLE_ENDIAN
  std::cout << "Is little endian" << std::endl;
#endif

#if SYSTEM_IS(Linux)
  std::cout << "Host is Linux" << std::endl;
#endif

#if SYSTEM_IS(Windows)
  std::cout << "Host is Windows" << std::endl;
#endif

#if not SYSTEM_IS(Windows)
  std::cout << "Host is NOT Windows" << std::endl;
#endif

#if SYSTEM_IS(Windows) and SYSTEM_IS(Linux)
  std::cout << "Is Windows and Linux really ?!?!" << std::endl;
#endif

  return 0;
}
