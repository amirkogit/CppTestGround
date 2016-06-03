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
