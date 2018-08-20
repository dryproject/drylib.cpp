/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "dry/base.hpp"
#include "dry/text/ascii.hpp"
#include "dry/text/printf.hpp"
#include "dry/text/utf8.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace dry { namespace bits { }}   // namespace dry::bits
namespace dry { namespace code { }}   // namespace dry::code
namespace dry { namespace crypto { }} // namespace dry::crypto
namespace dry { namespace data { }}   // namespace dry::data
namespace dry { namespace ffi { }}    // namespace dry::ffi
namespace dry { namespace geo { }}    // namespace dry::geo
namespace dry { namespace io { }}     // namespace dry::io
namespace dry { namespace lang { }}   // namespace dry::lang
namespace dry { namespace logic { }}  // namespace dry::logic
namespace dry { namespace math { }}   // namespace dry::math
namespace dry { namespace media { }}  // namespace dry::media
namespace dry { namespace meta { }}   // namespace dry::meta
namespace dry { namespace net { }}    // namespace dry::net
namespace dry { namespace qty { }}    // namespace dry::qty
namespace dry { namespace std { }}    // namespace dry::std
namespace dry { namespace sys { }}    // namespace dry::sys
namespace dry { namespace text { }}   // namespace dry::text
namespace dry { namespace time { }}   // namespace dry::time
namespace dry { namespace util { }}   // namespace dry::util
