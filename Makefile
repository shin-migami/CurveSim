.PHONY: all clean

OBJEXT := o
DEPEXT := d
CXX := g++
CXXFLAGS += -std=c++11
CXXFLAGS += -MMD # to generate dependencies
LDLIBS += -lc

SRC := $(wildcard CurveSim/*.cpp)
OBJS := $(patsubst %.cpp,%.$(OBJEXT),$(SRC))
DEPS := $(patsubst %.cpp,%.$(DEPEXT),$(SRC))
BIN := curvesim

all : $(BIN)

$(BIN) : $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

-include $(DEPS)

clean :
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(BIN)
