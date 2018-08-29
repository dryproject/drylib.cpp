/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "complex.hpp"
#include "float.hpp"
#include "integer.hpp"
#include "natural.hpp"
#include "rational.hpp"
#include "real.hpp"

#include <variant> /* for std::variant */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using number = ::std::variant<
    complex,
    float,
    int,
    integer,
    nat,
    natural,
    rational,
    real
  >;
}
