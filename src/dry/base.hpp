/* This is free and unencumbered software released into the public domain. */

#pragma once

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201703L
#error "DRYlib for C++ requires a C++17 compiler (CXXFLAGS='-std=c++17')"
#endif

////////////////////////////////////////////////////////////////////////////////

namespace dry {} // namespace dry

#include "base/bool.hpp"
#include "base/char.hpp"
#include "base/complex.hpp"
#include "base/float.hpp"
#include "base/integer.hpp"
#include "base/natural.hpp"
#include "base/optional.hpp"
#include "base/predicate.hpp"
#include "base/rational.hpp"
#include "base/real.hpp"
#include "base/string.hpp"
#include "base/word.hpp"

#include "base/misc.hpp"
