PROJECT		= test_helloworld

SRCS 		= helloworld.cpp \
              myfunc.cpp

OBJS		= helloworld.o \
              myfunc.o 

TARGET		= test_helloworld

CXX			= g++

CXXFLAGS	= -std=c++11

INCLUDE 	= -I./

all:
	$(CXX) -c $(CXXFLAGS) $(SRCS) $(INCLUDE)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

clean:
	rm $(OBJS) $(TARGET) 

