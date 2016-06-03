/*
* Code snippets to try C++11 and C++14 features
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

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

