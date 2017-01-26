PROJECT		= HelloWorld3

SRCS 		= 	main.cpp \
				Person.cpp
			 	
OBJS		= 	main.o \
				Person.o

TARGET		= 	HelloWorld3

CXX			= 	g++

CXXFLAGS	= 	-std=c++11

INCLUDE 	= 	-I./

all:
	$(CXX) -c $(CXXFLAGS) $(SRCS) $(INCLUDE)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

clean:
	rm $(OBJS) $(TARGET) 
