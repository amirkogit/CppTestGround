/*
 * main.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: ashrestha
 */
#include <iostream>
#include "Person.h"

using namespace std;

class Test {
public:
	Test(int value){ _data = value;}

	void Print()
	{
		cout << _data << endl;
	}

private:
	int _data;
};


int main()
{
	std::cout << "Hello world 3" << std::endl;

	for(int i = 0; i < 10; i++) {
		std::cout << "Test Eclipse..." << std::endl;
	}

	for(int i = 0; i < 4; i++) {
		std::cout << "Test Eclipse 222 ..." << std::endl;
	}

	Person p;
	p.SetData(45);
	p.Print();

	Test t(12);
	t.Print();
}



