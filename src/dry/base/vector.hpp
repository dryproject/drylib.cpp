/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <memory> /* for std::allocator */
#include <vector> /* for std::vector */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  template<
    typename T,
    typename Allocator = ::std::allocator<T>
  >
  using vector = ::std::vector<T, Allocator>;
}
