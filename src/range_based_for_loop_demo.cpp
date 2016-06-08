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
