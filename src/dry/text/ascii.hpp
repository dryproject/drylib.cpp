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
/* dry:text/ascii */

namespace dry { namespace text { namespace ascii {

  /**
   * Implements dry:text/ascii/string.
   */
  using string = dry::string;

  /**
   * Implements dry:text/ascii/string.
   */
  inline const string make_string(const char_ character) {
    return {}; // TODO
  }

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
  inline const string make_string(const char* const data) {
    return make_string(data, ::std::strlen(data));
  }

  /**
   * Implements dry:text/ascii/blank?.
   */
  inline bool is_blank(const char_ character) {
    return character == 0x20 || character == 0x09; // space or horizontal tab
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
   * Implements dry:text/ascii/compare.
   */
  inline int compare(const char_ character1,
                     const char_ character2) {
    return -1; // TODO
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
   * Implements dry:text/ascii/contains?.
   */
  inline bool contains(const string& string,
                       const dry::string& substring) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/contains?.
   */
  inline bool contains(const string& string,
                       const char* const substring) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/empty?.
   */
  inline bool empty(const string& string) {
    return string.size == 0;
  }

  /**
   * Implements dry:text/ascii/ends-with?.
   */
  inline bool ends_with(const string& string,
                        const char_ suffix) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/ends-with?.
   */
  inline bool ends_with(const string& string,
                        const dry::string& suffix) {
    if (suffix.size > string.size) return false;
    return ::std::strncmp(string.data + string.size - suffix.size, suffix.data, suffix.size) == 0;
  }

  /**
   * Implements dry:text/ascii/ends-with?.
   */
  inline bool ends_with(const string& string,
                        const char* const suffix) {
    const auto suffix_size = std::strlen(suffix);
    if (suffix_size > string.size) return false;
    return ::std::strncmp(string.data + string.size - suffix_size, suffix, suffix_size) == 0;
  }

  /**
   * Implements dry:text/ascii/equals?.
   */
  inline bool equals(const string& string1,
                     const string& string2) {
    return string1.size == string2.size && ::std::strncmp(string1.data, string2.data, string1.size);
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
   * Implements dry:text/ascii/reverse.
   */
  inline const string reverse(const string& string) {
    return {}; // TODO
  }

  /**
   * Implements dry:text/ascii/size.
   */
  inline nat size(const string& string) {
    return string.size;
  }

  /**
   * Implements dry:text/ascii/starts-with?.
   */
  inline bool starts_with(const string& string,
                          const char_ prefix) {
    return false; // TODO
  }

  /**
   * Implements dry:text/ascii/starts-with?.
   */
  inline bool starts_with(const string& string,
                          const dry::string& prefix) {
    if (prefix.size > string.size) return false;
    return ::std::strncmp(string.data, prefix.data, ::std::min(string.size, prefix.size)) == 0;
  }

  /**
   * Implements dry:text/ascii/starts-with?.
   */
  inline bool starts_with(const string& string,
                          const char* const prefix) {
    const auto prefix_size = std::strlen(prefix);
    if (prefix_size > string.size) return false;
    return ::std::strncmp(string.data, prefix, ::std::min(string.size, prefix_size)) == 0;
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

  /**
  * Implements dry:text/ascii/valid?.
  */
  inline bool is_valid(const char_ character) {
    return character <= 0x7F;
  }

  /**
  * Implements dry:text/ascii/valid?.
  */
  inline bool is_valid(const string& string) {
    return ::std::all_of(string.data, string.data + string.size, [](unsigned char c) {
      return c <= 0x7F;
    });
  }

}}} // namespace dry::text::ascii
