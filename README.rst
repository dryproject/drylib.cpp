**************
DRYlib for C++
**************

.. image:: https://img.shields.io/badge/license-Public%20Domain-blue.svg
   :alt: Project license
   :target: https://unlicense.org/

.. image:: https://img.shields.io/travis/dryproject/drylib.cpp/master.svg
   :alt: Travis CI build status
   :target: https://travis-ci.org/dryproject/drylib.cpp

|

http://drylib.org

Prerequisites
=============

* a `C++14 <https://en.wikipedia.org/wiki/C%2B%2B14>`__ compiler

Features
========

* All exported public symbols are namespaced with ``dry::``.

Caveats
=======

* Some core DRYlib type names are reserved words in C++, even when
  namespaced (specifically, ``bool``, ``char``, ``float``, and ``int``).
  For consistency, we nonetheless define type aliases for them, with an
  added underscore suffix to make these legal symbols (e.g., ``dry::bool_``).
  In generated code, the consistent type aliases will be used; in your own
  code, you can naturally use whichever names you prefer (``bool`` or
  ``dry::bool``), as the types in question are identical. And in case you
  prefer ``using namespace dry``, the distinction becomes moot altogether.

Installation
============

Usage
=====

::

   #include "drylib.hpp"

   using namespace dry;

Reference
=========

``core``
--------

=============== ================================================================
DRY Symbol      C++ Symbol
=============== ================================================================
``bool``        ``dry::bool_`` (type alias for ``bool``)
``char``        ``dry::char_`` (type alias for ``std::uint32_t``)
``complex``     ``dry::complex`` (struct)
``float``       ``dry::float_`` (type alias for ``double``)
``float32``     ``dry::float32`` (type alias for ``float``)
``float64``     ``dry::float64`` (type alias for ``double``)
``int``         ``dry::int_`` (type alias for ``long``)
``int8``        ``dry::int8`` (type alias for ``std::int8_t``)
``int16``       ``dry::int16`` (type alias for ``std::int16_t``)
``int32``       ``dry::int32`` (type alias for ``std::int32_t``)
``int64``       ``dry::int64`` (type alias for ``std::int64_t``)
``int128``      ``dry::int128`` (type alias for ``__int128``)
``integer``     ``dry::integer`` (struct)
``natural``     ``dry::natural`` (type alias ``dry::integer``)
``rational``    ``dry::rational`` (struct)
``real``        ``dry::real`` (struct)
``word``        ``dry::word`` (type alias for ``std::uint64_t`` or ``std::uint32_t``)
``word8``       ``dry::word8`` (type alias for ``std::uint8_t``)
``word16``      ``dry::word16`` (type alias for ``std::uint16_t``)
``word32``      ``dry::word32`` (type alias for ``std::uint32_t``)
``word64``      ``dry::word64`` (type alias for ``std::uint64_t``)
=============== ================================================================
