/* This is free and unencumbered software released into the public domain. */

#include "drylib.hpp"

#include <cstdlib> /* for EXIT_SUCCESS */

using namespace dry;
using namespace dry::text;

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
  const auto s = ascii::make_string("hello");
  ascii::length(s);

  printf::sprintf("Hello, %s!", "world");

  return EXIT_SUCCESS; // TODO
}
