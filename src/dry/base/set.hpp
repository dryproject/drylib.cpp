/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <functional> /* for std::less */
#include <memory>     /* for std::allocator */
#include <set>        /* for std::set */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  template<typename Key, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<Key>>
  using set = ::std::set<Key, Compare, Allocator>;
}
