/* This is free and unencumbered software released into the public domain. */

#ifndef __cplusplus
#error "DRYlib for C++ requires a C++ compiler"
#endif

#if __cplusplus < 201402L
#error "DRYlib for C++ requires a C++14 compiler (CXXFLAGS='-std=c++14')"
#endif

#include "drylib.hpp"

////////////////////////////////////////////////////////////////////////////////

// c++ -std=c++14 -DMAIN drylib.cpp
#ifdef MAIN
int main(int argc, char* argv[]) {
  return 0; // TODO
}
#endif
