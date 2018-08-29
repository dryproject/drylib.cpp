/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <utility> /* for std::pair */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  template<typename T>
  using interval = ::std::pair<T, T>;
}
