CXX     ?= c++
PANDOC  ?= pandoc

CPPFLAGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Werror
CXXFLAGS = -std=c++17

PACKAGE :=
VERSION := $(shell cat VERSION)

SOURCES :=

TARGETS := test

%.html: %.rst
	$(PANDOC) -o $@ -t html5 -s $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -o $@ -c $<

%: %.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) -o $@ $^ $(LOADLIBES) $(LDLIBS)

test: test.o

all: build

build: $(TARGETS)

check: test
	./test

dist:
	@echo "not implemented"; exit 2 # TODO

install:
	@echo "not implemented"; exit 2 # TODO

uninstall:
	@echo "not implemented"; exit 2 # TODO

clean:
	@rm -f *~ *.o $(TARGETS)

distclean: clean

mostlyclean: clean

.PHONY: check dist install clean distclean mostlyclean
.SECONDARY:
.SUFFIXES:
