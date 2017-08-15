This post shows how to setup a simple make file in order to build and test C++ applications quickly.

The folder structure looks as follows:
├── app.cpp
├── makefile
├── mylib.cpp
├── mylib.h

The make file defines the name of the project, includes the source and header files, defines a C++ compiler and other flags that can be passed to the compiler.

[code language="cpp"]
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
[/code]

The main function for the application is defined in app.cpp file. In mylib.h and mylib.cpp, a simple function is declared and defined that is used in app.cpp.

To build the project, execute the following

[code language="cpp"]
$make
[/code]

To run,

[code language="cpp"]
$./test_starter
[/code]

The program should output the following texts:

[code language="cpp"]
Starter project using make...
Printed from myfunc
[/code]

All source codes can be found the following link:
