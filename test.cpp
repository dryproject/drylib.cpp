/* This is free and unencumbered software released into the public domain. */

#include "drylib.hpp"

#include <cstdlib> /* for EXIT_SUCCESS */

using namespace dry;
using namespace dry::text;

////////////////////////////////////////////////////////////////////////////////

static void
test_text_ascii(void) {
  const auto s = ascii::make_string("hello");
  ascii::length(s);

  printf::sprintf("Hello, %s!", "world");
}

////////////////////////////////////////////////////////////////////////////////

int
main(int argc, char* argv[]) {
  test_text_ascii();
  return EXIT_SUCCESS;
}
