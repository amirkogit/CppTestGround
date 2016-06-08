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
