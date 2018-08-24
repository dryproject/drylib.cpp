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

namespace dry {
  using any = ::std::any;

  using bit = bool;

  using bool_ = bool;

  using char_ = char32_t;

  struct complex;

  using error = ::std::exception;

  using float_ = double;

  using float32 = float;

  using float64 = double;

  template<typename R, typename... Args>
  using function = ::std::function<R (Args...)>;

  using int_ = long;

  using int8 = ::std::int8_t;

  using int16 = ::std::int16_t;

  using int32 = ::std::int32_t;

  using int64 = ::std::int64_t;

#ifdef __SIZEOF_INT128__
  using int128 = __int128;
#else
#error "DRYlib for C++ requires compiler support for the __int128 type"
#endif

  struct integer;

  template<typename T>
  using interval = ::std::pair<T, T>;

  template<typename T, typename Allocator = ::std::allocator<T>>
  using list = ::std::forward_list<T, Allocator>;

  template<typename Key, typename Val, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<::std::pair<const Key, Val>>>
  using map = ::std::map<Key, Val, Compare, Allocator>;

  // see further below for dry::matrix

  using nat = unsigned long;

  struct natural;

  using none_t = ::std::nullopt_t;

  inline constexpr none_t none = ::std::nullopt;

  // see further below for dry::number

  template<typename T>
  using optional = ::std::optional<T>;

  template<typename... Args>
  using predicate = ::std::function<bool (Args...)>;

  // TODO: quantity

  struct rational;

  struct real;

  template<typename T>
  using result = ::std::pair<error, T>;

  // see further below for dry::scalar

  // TODO: seq

  template<typename Key, typename Compare = ::std::less<Key>, typename Allocator = ::std::allocator<Key>>
  using set = ::std::set<Key, Compare, Allocator>;

  struct string;

  struct symbol;

  // see further below for dry::tensor

  template<typename... Types>
  using tuple = ::std::tuple<Types...>;

  // TODO: unit

  // see further below for dry::vector

#if __WORDSIZE == 32
  using word = ::std::uint32_t;
#elif __WORDSIZE == 64
  using word = ::std::uint64_t;
#else
#error "DRYlib for C++ detected an unsupported size for __WORDSIZE"
#endif

  using word8 = ::std::uint8_t;

  using word16 = ::std::uint16_t;

  using word32 = ::std::uint32_t;

  using word64 = ::std::uint64_t;
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

struct dry::integer {
  dry::int128 value; // TODO
};

struct dry::natural {
  dry::int128 value; // TODO
};

struct dry::rational {
  dry::integer numerator;
  dry::integer denominator; /* denominator != 0 */
};

struct dry::real {
  dry::float64 value; // TODO
};

struct dry::complex {
  dry::real real;
  dry::real imaginary;
};

template<typename T>
struct dry::matrix {
  // TODO
};

struct dry::string {
  dry::nat size;
  const char* data;
};

struct dry::symbol {
  const char* data;
};
