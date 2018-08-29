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
#include "base/error.hpp"
#include "base/float.hpp"
#include "base/function.hpp"
#include "base/integer.hpp"
#include "base/interval.hpp"
#include "base/list.hpp"
#include "base/map.hpp"
#include "base/matrix.hpp"
#include "base/natural.hpp"
#include "base/number.hpp"
#include "base/optional.hpp"
#include "base/predicate.hpp"
#include "base/quantity.hpp"
#include "base/rational.hpp"
#include "base/real.hpp"
#include "base/result.hpp"
#include "base/scalar.hpp"
#include "base/seq.hpp"
#include "base/set.hpp"
#include "base/string.hpp"
#include "base/symbol.hpp"
#include "base/tensor.hpp"
#include "base/tuple.hpp"
#include "base/unit.hpp"
#include "base/vector.hpp"
#include "base/word.hpp"
