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
#include <set>          /* for std::set */
#include <string>       /* for std::string */
#include <tuple>        /* for std::tuple */
#include <utility>      /* for std::pair */
#include <variant>      /* for std::variant */
#include <vector>       /* for std::vector */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using any = ::std::any;

  using bit = bool;

  using error = ::std::exception;

  template<typename R, typename... Args>
  using function = ::std::function<R (Args...)>;

  template<typename T>
  using interval = ::std::pair<T, T>;

  template<typename T, typename Allocator = ::std::allocator<T>>
  using list = ::std::forward_list<T, Allocator>;

  template<typename Key, typename Val, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<::std::pair<const Key, Val>>>
  using map = ::std::map<Key, Val, Compare, Allocator>;

  // see further below for dry::matrix

  // see further below for dry::number

  // TODO: quantity

  template<typename T>
  using result = ::std::pair<error, T>;

  // see further below for dry::scalar

  // TODO: seq

  template<typename Key, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<Key>>
  using set = ::std::set<Key, Compare, Allocator>;

  struct symbol;

  // see further below for dry::tensor

  template<typename... Types>
  using tuple = ::std::tuple<Types...>;

  // TODO: unit

  // see further below for dry::vector
}

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

  using scalar = ::std::variant<
    bit,
    bool_,
    char_,
    number,
    word
  >;

  template<
    typename T,
    typename Allocator = ::std::allocator<T>
  >
  using vector = ::std::vector<T, Allocator>;

  template<typename T>
  struct matrix;

  template<typename T>
  using tensor = ::std::variant<
    scalar,
    vector<T>,
    matrix<T>
  >;
}

////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct dry::matrix {
  // TODO
};

struct dry::symbol {
  const char* data;
};
