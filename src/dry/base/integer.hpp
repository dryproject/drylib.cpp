/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <cstdint> /* for __WORDSIZE, std::int*_t */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using int_ = long;

  using int8 = ::std::int8_t;

  using int16 = ::std::int16_t;

  using int32 = ::std::int32_t;

  using int64 = ::std::int64_t;

#ifdef __SIZEOF_INT128__
  using int128 = __int128;
#else
#error "DRYlib for C++ requires compiler support for the __int128 type"
#endif

  struct integer;
}

////////////////////////////////////////////////////////////////////////////////

struct dry::integer {
  dry::int128 value; // TODO
};
