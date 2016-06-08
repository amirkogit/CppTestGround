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

#include "unordered_sets_multisets_demo.h"

#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

UnorderedSetsMultiSetsDemo::UnorderedSetsMultiSetsDemo()
{
}


UnorderedSetsMultiSetsDemo::~UnorderedSetsMultiSetsDemo()
{
}

void UnorderedSetsMultiSetsDemo::SimpleMultiset()
{
    unordered_multiset<string> cities{ "Davie","Plantation","Sunrise","Miami","Key-West" };

    // print each element of the set. The order in which the values are printed is undefined!!!
    for (const auto& elem : cities) {
        cout << elem << " ";
    }
    cout << endl;

    // insert additional values: this may change the order in while printing because hash policy will be changed
    cities.insert({ "Alameda","San Jose","Cupertino","San Franscisco" });

    cout << "After inserting additional values\n";

    // print each element
    for (const auto& elem : cities) {
        cout << elem << " ";
    }
}
