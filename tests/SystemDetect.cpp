#include "SystemDetect.hpp"

#include <iostream>

int main()
{
  //std::cout<<SystemDetect::getArchitecture()<<std::endl;
#if ARCHITECTURE_IS(lll)
  std::cout<<"OO"<<std::endl;
#else

#endif
  return 0;
}
