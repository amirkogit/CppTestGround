#include "range_based_for_loop_demo.h"

#include <vector>
#include <iostream>

range_based_for_loop_demo::range_based_for_loop_demo()
{
}


range_based_for_loop_demo::~range_based_for_loop_demo()
{
}

void range_based_for_loop_demo::MultiplyVectorElements()
{
	std::cout << "Multiply vector elements\n";

	std::vector<double> vec;
	vec = { 2.5, 3.6, 5.8, 9.4, 3.6 };

	for (auto &elem : vec) {
		std::cout << "element = " << elem << "\n";
		elem *= 3;
		std::cout << "element*3 = " << elem << "\n";
	}
}

void range_based_for_loop_demo::AddAllArrayElements()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	long sum = 0;

	for (auto x : array) {
		sum += x;
	}

	std::cout << "Sum = " << sum;
}
