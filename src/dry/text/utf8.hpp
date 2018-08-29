/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "../base/string.hpp"
#include "ascii.hpp"

////////////////////////////////////////////////////////////////////////////////
/* dry:text/utf8 */

namespace dry { namespace text { namespace utf8 {
  /**
   * Implements dry:text/utf8/string.
   */
  using string = dry::string;

  using ascii::make_string;
  using ascii::is_blank;
  using ascii::empty;
  using ascii::is_valid;
  using ascii::size;
  using ascii::length;
  using ascii::nth;
  using ascii::equals;
  using ascii::contains;
  using ascii::ends_with;
  using ascii::starts_with;
  using ascii::compare;
  using ascii::concat;
  using ascii::reverse;
  using ascii::trim;
  using ascii::trim_left;
  using ascii::trim_right;
}}} // namespace dry::text::utf8
