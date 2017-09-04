/* This is free and unencumbered software released into the public domain. */

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201402L
#error "DRYlib for C++ requires a C++14 compiler (CXXFLAGS='-std=c++14')"
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

  using natural = integer;

  struct rational;

  struct real;

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

////////////////////////////////////////////////////////////////////////////////

struct dry::rational {
  dry::integer numerator;
  dry::integer denominator; /* denominator != 0 */
};

////////////////////////////////////////////////////////////////////////////////

struct dry::real {
  dry::float64 value; // TODO
};

////////////////////////////////////////////////////////////////////////////////

struct dry::complex {
  dry::real real;
  dry::real imaginary;
};

////////////////////////////////////////////////////////////////////////////////
