/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include <cstdint> /* for __WORDSIZE, std::*int_t */

////////////////////////////////////////////////////////////////////////////////

namespace dry {
  using bool_ = bool;

  using char_ = std::uint32_t;

  struct complex;

  using float_ = double;

  using float32 = float;

  using float64 = double;

  using int_ = long;

  using int8 = std::int8_t;

  using int16 = std::int16_t;

  using int32 = std::int32_t;

  using int64 = std::int64_t;

  using int128 = __int128; // TODO: protect with macro

  struct integer;

  using nat = unsigned long;

  struct natural;

  // TODO: number

  struct rational;

  struct real;

  struct string;

  // TODO: symbol

#if __WORDSIZE == 32
  using word = std::uint32_t;
#elif __WORDSIZE == 64
  using word = std::uint64_t;
#else
#error "unsupported size for __WORDSIZE"
#endif

  using word8 = std::uint8_t;

  using word16 = std::uint16_t;

  using word32 = std::uint32_t;

  using word64 = std::uint64_t;
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

struct dry::string {
  dry::nat size;
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
   * Implements dry:text/ascii/blank?.
   */
  inline bool is_blank(const string& s) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/empty?.
   */
  inline bool is_empty(const string& s) {
    return s.size == 0;
  }

  /**
   * Implements dry:text/ascii/size.
   */
  inline nat size(const string& s) {
    return s.size;
  }

  /**
   * Implements dry:text/ascii/length.
   */
  inline nat length(const string& s) {
    return 0; // TODO
  }

  /**
   * Implements dry:text/ascii/nth.
   */
  inline char_ nth(const string& s,
                   const nat n) {
    return 0; // TODO
  }

  /**
   * Implements dry:text/ascii/equals?.
   */
  inline bool equals(const string& s1,
                     const string& s2) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/contains?.
   */
  inline bool contains(const string& s,
                       const char_ c) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/ends-with?.
   */
  inline bool ends_with(const string& s1,
                        const string& s2) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/starts-with?.
   */
  inline bool starts_with(const string& s1,
                          const string& s2) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/compare.
   */
  inline int compare(const string& s1,
                     const string& s2) {
    return -1; // TODO
  }

  /**
   * Implements dry:text/ascii/concat.
   */
  inline const string concat(const string& s1,
                             const string& s2) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/reverse.
   */
  inline const string reverse(const string& s) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/trim.
   */
  inline const string trim(const string& s) {
    return s; // TODO
  }

  /**
   * Implements dry:text/ascii/trim-left.
   */
  inline const string trim_left(const string& s) {
    return s; // TODO
  }

  /**
   * Implements dry:text/ascii/trim-right.
   */
  inline const string trim_right(const string& s) {
    return s; // TODO
  }

}}} // namespace dry::text::ascii

////////////////////////////////////////////////////////////////////////////////
/* dry:text/printf */

namespace dry { namespace text { namespace printf {

}}} // namespace dry::text::printf

////////////////////////////////////////////////////////////////////////////////
/* dry:text/utf8 */

namespace dry { namespace text { namespace utf8 {
  /**
   * Implements dry:text/utf8/string.
   */
  using string = dry::string;

  using ascii::is_blank;
  using ascii::is_empty;
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
