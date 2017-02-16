PROJECT     = templates_demo

SRCS        = sample.cpp

OBJS        = sample.o

TARGET      = templates_demo

CXX         = g++

CXXFLAGS    = -std=c++11

INCLUDE     = -I./

all:
	$(CXX) -c $(CXXFLAGS) $(SRCS) $(INCLUDE)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

clean:
	rm $(OBJS) $(TARGET) 