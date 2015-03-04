#pragma once

#include <initializer_list>
#include <vector>

class Initializer_Demo{
public:
	Initializer_Demo(int a, int b);

	Initializer_Demo(std::initializer_list<int> vals);

	void PrintSelf();

private:
	std::vector<int> _valueList;
};