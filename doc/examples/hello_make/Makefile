CXX      ?= c++

CXXFLAGS ?= -Wall -Wextra -Wno-unused-parameter -Wno-unused-function
CXXFLAGS += -std=c++17
CPPFLAGS ?=

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
