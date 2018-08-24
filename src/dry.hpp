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
#include "dry/bits.hpp"
#include "dry/code.hpp"
#include "dry/crypto.hpp"
#include "dry/data.hpp"
#include "dry/ffi.hpp"
#include "dry/geo.hpp"
#include "dry/io.hpp"
#include "dry/lang.hpp"
#include "dry/logic.hpp"
#include "dry/math.hpp"
#include "dry/media.hpp"
#include "dry/meta.hpp"
#include "dry/net.hpp"
#include "dry/qty.hpp"
#include "dry/std.hpp"
#include "dry/sys.hpp"
#include "dry/text.hpp"
#include "dry/time.hpp"
#include "dry/util.hpp"
