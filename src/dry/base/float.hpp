/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using float_ = double;

  using float16 = float; // TODO: _Float16

  using float32 = float;

  using float64 = double;

#ifdef __FLOAT128__
  using float128 = __float128;
#endif
}
