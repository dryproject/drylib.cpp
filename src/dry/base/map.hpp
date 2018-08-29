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
#include <map>        /* for std::map */
#include <memory>     /* for std::allocator */
#include <utility>    /* for std::pair */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  template<typename Key, typename Val, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<::std::pair<const Key, Val>>>
  using map = ::std::map<Key, Val, Compare, Allocator>;
}
