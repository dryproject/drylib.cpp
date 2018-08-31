/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "bool.hpp"
#include "char.hpp"
#include "number.hpp"
#include "word.hpp"

#include <variant> /* for std::variant */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using scalar = ::std::variant<
    //bit, // TODO
    bool_,
    char_,
    number,
    word
  >;
}
