/* This is free and unencumbered software released into the public domain. */

#include "drylib.hpp"

#include <cstdlib> /* for EXIT_SUCCESS */

using namespace dry;
using namespace dry::text;

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
  const string s{5, "hello"};
  ascii::length(s);

  return EXIT_SUCCESS; // TODO
}
