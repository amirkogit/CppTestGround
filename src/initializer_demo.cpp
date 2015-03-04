#include "initializer_demo.h"
#include <iostream>

Initializer_Demo::Initializer_Demo(int a, int b)
{
	std::cout << "Initializer_Demo default constructor called. \n";
	_valueList.push_back(a);
	_valueList.push_back(b);
}

Initializer_Demo::Initializer_Demo(std::initializer_list<int> vals)
{
	std::cout << "Initializer_Demo initializer list constructor called. \n";
	for (auto p = vals.begin(); p != vals.end(); ++p) {
		_valueList.push_back(*p);
	}
}

void Initializer_Demo::PrintSelf()
{
	std::cout << "Printing values...\n";
	for (auto p = _valueList.begin(); p != _valueList.end(); ++p) {
		std::cout << *p << "\n";
	}
	std::cout << "\n";
}
