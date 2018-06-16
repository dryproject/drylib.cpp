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
  using result = std::pair<error, T>;

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

////////////////////////////////////////////////////////////////////////////////
/* dry:bits */

namespace dry { namespace bits { }} // namespace dry::bits

////////////////////////////////////////////////////////////////////////////////
/* dry:code */

namespace dry { namespace code { }} // namespace dry::code

////////////////////////////////////////////////////////////////////////////////
/* dry:crypto */

namespace dry { namespace crypto { }} // namespace dry::crypto

////////////////////////////////////////////////////////////////////////////////
/* dry:data */

namespace dry { namespace data { }} // namespace dry::data

////////////////////////////////////////////////////////////////////////////////
/* dry:ffi */

namespace dry { namespace ffi { }} // namespace dry::ffi

////////////////////////////////////////////////////////////////////////////////
/* dry:geo */

namespace dry { namespace geo { }} // namespace dry::geo

////////////////////////////////////////////////////////////////////////////////
/* dry:io */

namespace dry { namespace io { }} // namespace dry::io

////////////////////////////////////////////////////////////////////////////////
/* dry:lang */

namespace dry { namespace lang { }} // namespace dry::lang

////////////////////////////////////////////////////////////////////////////////
/* dry:logic */

namespace dry { namespace logic { }} // namespace dry::logic

////////////////////////////////////////////////////////////////////////////////
/* dry:math */

namespace dry { namespace math { }} // namespace dry::math

////////////////////////////////////////////////////////////////////////////////
/* dry:media */

namespace dry { namespace media { }} // namespace dry::media

////////////////////////////////////////////////////////////////////////////////
/* dry:meta */

namespace dry { namespace meta { }} // namespace dry::meta

////////////////////////////////////////////////////////////////////////////////
/* dry:net */

namespace dry { namespace net { }} // namespace dry::net

////////////////////////////////////////////////////////////////////////////////
/* dry:qty */

namespace dry { namespace qty { }} // namespace dry::qty

////////////////////////////////////////////////////////////////////////////////
/* dry:std */

namespace dry { namespace std { }} // namespace dry::std

////////////////////////////////////////////////////////////////////////////////
/* dry:sys */

namespace dry { namespace sys { }} // namespace dry::sys

////////////////////////////////////////////////////////////////////////////////
/* dry:text */

namespace dry { namespace text { }} // namespace dry::text

////////////////////////////////////////////////////////////////////////////////
/* dry:time */

namespace dry { namespace time { }} // namespace dry::time

////////////////////////////////////////////////////////////////////////////////
/* dry:util */

namespace dry { namespace util { }} // namespace dry::util

////////////////////////////////////////////////////////////////////////////////
/* dry:text/ascii */

namespace dry { namespace text { namespace ascii {

  /**
   * Implements dry:text/ascii/string.
   */
  using string = dry::string;

  /**
   * Implements dry:text/ascii/string.
   */
  inline const string make_string(const char* data,
                                  const nat size) {
    return {size, data};
  }

  /**
   * Implements dry:text/ascii/string.
   */
  inline const string make_string(const char* data) {
    return make_string(data, ::std::strlen(data));
  }

  /**
   * Implements dry:text/ascii/blank?.
   */
  inline bool is_blank(const string& string) {
    return ::std::all_of(string.data, string.data + string.size, [](unsigned char c) {
      return c == 0x20 || c == 0x09; // space or horizontal tab
    });
  }

  /**
   * Implements dry:text/ascii/empty?.
   */
  inline bool empty(const string& string) {
    return string.size == 0;
  }

  /**
  * Implements dry:text/ascii/valid?.
  */
  inline bool is_valid(const string& string) {
    return ::std::all_of(string.data, string.data + string.size, [](unsigned char c) {
      return c <= 0x7F;
    });
  }

  /**
   * Implements dry:text/ascii/size.
   */
  inline nat size(const string& string) {
    return string.size;
  }

  /**
   * Implements dry:text/ascii/length.
   */
  inline nat length(const string& string) {
    return string.size;
  }

  /**
   * Implements dry:text/ascii/nth.
   */
  inline optional<char_> nth(const string& string,
                             const nat index) {
    if (index >= string.size) return none;
    return string.data[index];
  }

  /**
   * Implements dry:text/ascii/equals?.
   */
  inline bool equals(const string& string1,
                     const string& string2) {
    return string1.size == string2.size && ::std::strncmp(string1.data, string2.data, string1.size);
  }

  /**
   * Implements dry:text/ascii/contains?.
   */
  inline bool contains(const string& string,
                       const char_ character) {
    if (character > 0x7F) return false;
    return ::std::any_of(string.data, string.data + string.size, [character](unsigned char c) {
      return character == c;
    });
  }

  /**
   * Implements dry:text/ascii/ends-with?.
   */
  inline bool ends_with(const dry::string& string,
                        const dry::string& suffix) {
    if (suffix.size > string.size) return false;
    return ::std::strncmp(string.data + string.size - suffix.size, suffix.data, suffix.size) == 0;
  }

  /**
   * Implements dry:text/ascii/starts-with?.
   */
  inline bool starts_with(const dry::string& string,
                          const dry::string& prefix) {
    if (prefix.size > string.size) return false;
    return ::std::strncmp(string.data, prefix.data, ::std::min(string.size, prefix.size)) == 0;
  }

  /**
   * Implements dry:text/ascii/compare.
   */
  inline int compare(const string& string1,
                     const string& string2) {
    return ::std::strncmp(string1.data, string2.data, ::std::min(string1.size, string2.size)); // FIXME
  }

  /**
   * Implements dry:text/ascii/concat.
   */
  inline const string concat(const string& string1,
                             const string& string2) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/reverse.
   */
  inline const string reverse(const string& string) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/trim.
   */
  inline const string trim(const string& string) {
    return string; // TODO
  }

  /**
   * Implements dry:text/ascii/trim-left.
   */
  inline const string trim_left(const string& string) {
    return string; // TODO
  }

  /**
   * Implements dry:text/ascii/trim-right.
   */
  inline const string trim_right(const string& string) {
    return string; // TODO
  }

}}} // namespace dry::text::ascii

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

////////////////////////////////////////////////////////////////////////////////
