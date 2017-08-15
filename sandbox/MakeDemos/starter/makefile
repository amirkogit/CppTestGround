PROJECT		= make_starter

SRCS 		= app.cpp \
              mylib.cpp

OBJS		= app.o \
              mylib.o 

TARGET		= test_starter

CXX			= g++

CXXFLAGS	= -std=c++11

INCLUDE 	= -I./

all:
	$(CXX) -c $(CXXFLAGS) $(SRCS) $(INCLUDE)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

clean:
	rm $(OBJS) $(TARGET) 

