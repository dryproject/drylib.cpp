CXX      ?= c++
CXXFLAGS ?= -Wall -Wextra -Wno-unused-parameter -Wno-unused-function
CXXFLAGS += -std=c++17
CXXFLAGS += $(shell pkg-config --cflags-only-other drylib-cpp)
CPPFLAGS ?=
CPPFLAGS += $(shell pkg-config --cflags-only-I drylib-cpp)
LDFLAGS  ?=
LDFLAGS  += $(shell pkg-config --libs-only-L drylib-cpp)
LDFLAGS  += $(shell pkg-config --libs-only-other drylib-cpp)
LDLIBS   ?=
LDLIBS   += $(shell pkg-config --libs-only-l drylib-cpp)

SOURCES  := hello.cpp
OBJECTS  := hello.o
TARGETS  := hello

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -o $@ -c $<

%: %.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) -o $@ $^ $(LOADLIBES) $(LDLIBS)

hello: $(OBJECTS)

all: hello

clean:
	@rm -f *~ $(TARGETS) $(OBJECTS)

.PHONY: clean
.SECONDARY:
.SUFFIXES:
