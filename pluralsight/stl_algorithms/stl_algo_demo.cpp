/*
* Pluralsight : Beautiful STL Algorithms
*
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

#include "stl_algo_demo.h"

// standard library header includes
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////
// entry point for running hacker rank challeges problems
void STLAlgorithms::RunAllDemos()
{
    std::cout << "Running all pluralsight STL Algorithms demo" << endl;
    std::cout << "*********************************************" << endl;

    RunModule2Demo();

    RunModule3Demo();

    RunModule4Demo();

    RunModule5Demo();

    RunModule6Demo();

    RunModule7Demo();

    // wait for user input char
    getchar();
}
