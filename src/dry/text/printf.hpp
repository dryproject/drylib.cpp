/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

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
/* dry:text/printf */

namespace dry { namespace text { namespace printf {

  /**
   * Implements dry:text/printf/sprintf.
   */
  template<typename Allocator = ::std::allocator<char>>
  inline string sprintf(const char* format, ...) {
    Allocator alloc;

    va_list args;
    va_start(args, format);
    const int size = ::std::vsnprintf(nullptr, 0, format, args);
    va_end(args);
    assert(size >= 0);

    va_start(args, format);
    (void)::std::vsnprintf(nullptr, 0, format, args); // TODO
    va_end(args);
    assert(size >= 0);

    return {}; // TODO
  }

}}} // namespace dry::text::printf
