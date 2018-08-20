/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "../base.hpp"
#include "ascii.hpp"

#include <algorithm>    /* for std::max(), std::min(), ... */
#include <any>          /* for std::any */
#include <cassert>      /* for assert() */
#include <cstdarg>      /* for std::vsnprintf(), va_* */
#include <cstdint>      /* for __WORDSIZE, std::*int_t */
#include <cstring>      /* for std::strlen(), std::strncmp() */
#include <exception>    /* for std::exception */
#include <forward_list> /* for std::forward_list */
#include <functional>   /* for std::function */
#include <map>          /* for std::map */
#include <memory>       /* for std::allocator, std::unique_ptr */
#include <optional>     /* for std::optional */
#include <set>          /* for std::set */
#include <string>       /* for std::string */
#include <tuple>        /* for std::tuple */
#include <utility>      /* for std::pair */
#include <variant>      /* for std::variant */
#include <vector>       /* for std::vector */

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
