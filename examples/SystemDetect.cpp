#include "SystemDetect.hpp"

#include <iostream>

int main() {
  std::cout << "System : " << SystemDetect::getSystem()
  << std::endl;
  std::cout << "Architecture : " << SystemDetect::getArchitecture()
            << std::endl;
  std::cout << "Base architecture : " << SystemDetect::getBaseArchitecture()
            << std::endl;
  std::cout << "C compiler : " << SystemDetect::getCCompiler() << std::endl;
  std::cout << "C compiler version : " << SystemDetect::getCCompilerVersion()
            << std::endl;
  std::cout << "C compiler major : " << SystemDetect::getCCompilerMajorVersion()
            << std::endl;
  std::cout << "C compiler minor : " << SystemDetect::getCCompilerMinorVersion()
            << std::endl;
  std::cout << "C compiler patch : " << SystemDetect::getCCompilerPatchVersion()
            << std::endl;
  std::cout << "CXX compiler : " << SystemDetect::getCXXCompiler() << std::endl;
  std::cout << "CXX compiler version : "
            << SystemDetect::getCXXCompilerVersion() << std::endl;
  std::cout << "CXX compiler major : "
            << SystemDetect::getCXXCompilerMajorVersion() << std::endl;
  std::cout << "CXX compiler minor : "
            << SystemDetect::getCXXCompilerMinorVersion() << std::endl;
  std::cout << "CXX compiler patch : "
            << SystemDetect::getCXXCompilerPatchVersion() << std::endl;
  std::cout << "Endianness : " << SystemDetect::getEndianness() << std::endl;
  std::cout << "Is bigendian : " << SystemDetect::isBigEndian() << std::endl;
  std::cout << "Is littleendian : " << SystemDetect::isLittleEndian()
            << std::endl;
}
