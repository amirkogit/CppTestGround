#include "explicit_initialization_demo.h"
#include <iostream>

Explicit_Initialization_Demo::Explicit_Initialization_Demo()
{
}


Explicit_Initialization_Demo::~Explicit_Initialization_Demo()
{
}

void Explicit_Initialization_Demo::Fundamental_Types_Explicit_Initialization()
{
	int i1;				// not initialized
	int i2 = int();		// initialized to 0
	int i3{};			// initialized to 0

	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;
	std::cout << "i3 = " << i3 << std::endl;
}
