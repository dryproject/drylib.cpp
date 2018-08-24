/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <cstdint> /* for __WORDSIZE, std::uint*_t */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
#if __WORDSIZE == 32
  using word = ::std::uint32_t;
#elif __WORDSIZE == 64
  using word = ::std::uint64_t;
#else
#error "DRYlib for C++ detected an unsupported size for __WORDSIZE"
#endif

  using word8 = ::std::uint8_t;

  using word16 = ::std::uint16_t;

  using word32 = ::std::uint32_t;

  using word64 = ::std::uint64_t;
}
