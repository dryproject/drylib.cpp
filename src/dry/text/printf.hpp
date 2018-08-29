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

#include <cassert> /* for assert() */
#include <cstdarg> /* for std::vsnprintf(), va_* */
#include <memory>  /* for std::allocator */

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
