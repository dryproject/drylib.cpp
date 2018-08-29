/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "matrix.h"
#include "scalar.h"
#include "vector.h"

#include <variant> /* for std::variant */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  template<typename T>
  using tensor = ::std::variant<
    scalar,
    vector<T>,
    matrix<T>
  >;
}
