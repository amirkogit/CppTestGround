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

#include "algorithms_demo.h"

#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "common_utilities.h"

using namespace std;

AlgorithmsDemo::AlgorithmsDemo()
{
}


AlgorithmsDemo::~AlgorithmsDemo()
{
}

void AlgorithmsDemo::SimpleTransform()
{
    std::set<std::string> name_list;
    std::vector<std::string> name_list_capitalized;

    // insert some names
    name_list.insert("jill");
    name_list.insert("stephan");
    name_list.insert("mike");

    // print elements
    CommonUtilities::PrintElements(name_list, "Before capitalizing...");

    // transform each element from name_list to name_list_capitalized
    // capitalize each element

    std::transform(name_list.begin(), name_list.end(),           // source
                   std::back_inserter(name_list_capitalized),   // destination
                   CommonUtilities::ToUpper);                   // operation

    // print elements
    CommonUtilities::PrintElements(name_list_capitalized, "After capitalizing...");
}
