#include "lamda_demo.h"
#include <iostream>
#include <functional>

Lamda_Demo::Lamda_Demo()
{
}


Lamda_Demo::~Lamda_Demo()
{
}

void Lamda_Demo::SimpleLamda()
{
	// define a simple lambda expression
	auto l = [] { 
		std::cout << "Hello from lambda" << std::endl;
	};

	l();
}

void Lamda_Demo::ParameterizedLamda()
{
	// define a lambda expression taking const string as an argument
	auto parameter_lambda = [](const std::string &s) {
		std::cout << s.c_str() << std::endl;
	};

	parameter_lambda("Hello Lambda");
	parameter_lambda("Hello Again");
}

void Lamda_Demo::ReturnTypeLambda()
{
	// this lambda expression returns a double value
	auto return_double_lambda = []()->double {
		return 555.5;
	};

	std::cout << "\nReturn value from lambda = " << return_double_lambda();
}

void Lamda_Demo::CaptureLambda()
{
	int x = 0;
	int y = 90;

	// pass x by value and y by reference
	auto mylambda = [x, &y]() {
		std::cout << std::endl;
		std::cout << "x= " << x << std::endl;
		std::cout << "y= " << y << std::endl;
		++y; // increment y as this is passed as reference
		//++x; // this will not compile!
	};

	x = y = 100;
	mylambda();
	mylambda();

	std::cout << "Final value of y= " << y << std::endl;
}

void Lamda_Demo::MutableLambda()
{
	int id = 0;
	auto l = [id]() mutable {
		std::cout << "id: " << id << std::endl;
		++id;
	};

	id = 80;
	l();
	l();
	l();
	std::cout << "Final value of id: " << id << std::endl;
}

std::function<int(int, int)> ReturnSumLambda()
{
	return[](int x, int y) {
		return x + y;
	};
}

void Lamda_Demo::ReturnLambda()
{
	auto lf = ReturnSumLambda();
	std::cout << "Result of (6,7) from ReturnSumLambda: " << lf(6, 7);
}

