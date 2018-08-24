/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <optional> /* for std::optional */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using none_t = ::std::nullopt_t;

  inline constexpr none_t none = ::std::nullopt;

  template<typename T>
  using optional = ::std::optional<T>;
}
