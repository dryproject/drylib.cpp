PACKAGE  := drylib-cpp
VERSION  := $(shell cat VERSION)

CXX      ?= c++
CPPFLAGS ?= -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Werror
CPPFLAGS += -I src
CXXFLAGS ?=
CXXFLAGS += -std=c++17
SED      ?= sed

PANDOC   ?= pandoc

INSTALL  ?= install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA    = $(INSTALL) -m 644

prefix     ?= /usr/local
exec_prefix = $(prefix)
includedir  = $(prefix)/include
libdir      = $(exec_prefix)/lib

HEADERS  := $(wildcard src/*.hpp src/*/*.hpp src/*/*/*.hpp)
SOURCES  := $(HEADERS)
OBJECTS  :=
TARGETS  :=

%.html: %.rst
	$(PANDOC) -o $@ -t html5 -s $<

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -o $@ -c $<

%: %.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) -o $@ $^ $(LOADLIBES) $(LDLIBS)

drylib-cpp.pc: etc/pkgconfig/drylib-cpp.pc.in
	$(SED) -e 's:@prefix@:$(prefix):g' -e 's:@version@:$(VERSION):g' $^ > $@

test: test.o

all: check

check: test
	./test

dist:
	@echo "not implemented"; exit 2 # TODO

installdirs:
	$(INSTALL) -d $(DESTDIR)$(libdir)
	$(INSTALL) -d $(DESTDIR)$(libdir)/pkgconfig
	$(INSTALL) -d $(DESTDIR)$(includedir)
	$(INSTALL) -d $(DESTDIR)$(includedir)/dry
	$(INSTALL) -d $(DESTDIR)$(includedir)/dry/base
	$(INSTALL) -d $(DESTDIR)$(includedir)/dry/meta
	$(INSTALL) -d $(DESTDIR)$(includedir)/dry/text

install: installdirs drylib-cpp.pc $(TARGETS) $(HEADERS)
	$(INSTALL_DATA) drylib-cpp.pc $(DESTDIR)$(libdir)/pkgconfig/drylib-cpp.pc
	$(foreach file,$(HEADERS),$(INSTALL_DATA) $(file) $(DESTDIR)$(includedir)/$(file:src/%=%);)

uninstall:
	@echo "not implemented"; exit 2 # TODO

clean:
	@rm -f test *~ *.o $(TARGETS) $(OBJECTS)

distclean: clean

mostlyclean: clean

.PHONY: check dist installdirs install install-strip clean distclean mostlyclean
.SECONDARY:
.SUFFIXES:
