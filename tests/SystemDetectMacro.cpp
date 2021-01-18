#include "SystemDetectMacro.hpp"

#include <iostream>

int main() {
#if ARCHITECTURE_IS(x86_64)
  std::cout << "x86_64" << std::endl;
#else
  std::cout << "not x86_64" << std::endl;
#endif

#if BASE_ARCHITECTURE_IS(x86)
  std::cout << "OUI" << std::endl;
#endif

#if CXX_COMPILER_MAJOR_VERSION(10) and CXX_COMPILER_MINOR_VERSION(2)
  std::cout << "Bingo" << std::endl;
#endif

#if CXX_COMPILER_MAJOR_VERSION(10) and CXX_COMPILER_MINOR_VERSION(3)
  std::cout << "Bingo2" << std::endl;
#endif

#if CXX_COMPILER_MAJOR_VERSION(9) and CXX_COMPILER_MINOR_VERSION(2)
  std::cout << "Bingo3" << std::endl;
#endif

#if IS_BIG_ENDIAN()
  std::cout << "Is big endian" << std::endl;
#endif

#if IS_LITTLE_ENDIAN()
  std::cout << "Is little endian" << std::endl;
#endif

  return 0;
}
