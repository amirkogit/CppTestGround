all: hello.exe

clean:
	rm main.o hello.exe

hello.exe: main.o
	g++ -g -o hello main.o

main.o:
	g++ -c -g main.cpp
	