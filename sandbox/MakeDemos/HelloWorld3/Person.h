/*
 * Person.h
 *
 *  Created on: Jan 25, 2017
 *      Author: ashrestha
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

class Person {
public:
	Person();
	virtual ~Person();

	void SetData(int data)
	{
		_data = data;
	}

	void Print()
	{
		std::cout << "Person's data: " << _data << std::endl;
	}

private:
	int _data;
};

#endif /* PERSON_H_ */
