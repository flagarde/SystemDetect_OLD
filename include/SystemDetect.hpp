#pragma once

#include <cstdint>

namespace SystemDetect
{
  
enum class Arch : std::uint_fast8_t
{
  aarch64,
  alpha,
  arm,
  armv2,
  armv3,
  armv4,
  armv5,
  armv6,
  armv7,
  armv8,
  blackfin,
  ia64,
  i686,
  mips,
  m68k,
  parisc,
  powerpc,
  powerpc64,
  powerpc64le,
  rs6000,
  sh,
  sparc8,
  sparc9,
  s370,
  s390,
  s390x,
  x86_64,
  //The architecture
  arch=@ARCH@
};

/*
static constexpr int getArchitecture()
{
  return static_cast<int>(Arch::arch);
}
*/
}

#define ARCHITECTURE_IS(ARCH)(ARCH == lkj)
