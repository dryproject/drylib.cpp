/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "real.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  struct complex;
}

////////////////////////////////////////////////////////////////////////////////

struct dry::complex {
  dry::real real;
  dry::real imaginary;
};
