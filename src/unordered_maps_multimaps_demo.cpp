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

#include "unordered_maps_multimaps_demo.h"
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

UnorderedMapsMultiMapsDemo::UnorderedMapsMultiMapsDemo()
{
}


UnorderedMapsMultiMapsDemo::~UnorderedMapsMultiMapsDemo()
{
}

void UnorderedMapsMultiMapsDemo::SimpleMultimap()
{
    unordered_map<string, int> name_age_map{ {"Jack",34},{"Mill",50},{"Josh",65} };

    // print each element
    for (const auto& elem : name_age_map) {
        cout << elem.first << ": " << elem.second << endl;
    }

    cout << "\nAfter value changes:\n";

    // double the ages
    for (pair<const string, int>& elem : name_age_map) {
        elem.second *= 2;
        //elem.first = "not possible!!";    // ERROR: as the key is constant we cannot modify this !!
    }

    // print each element again
    for (const auto& elem : name_age_map) {
        cout << elem.first << ": " << elem.second << endl;
    }

    // add some more elements (different ways of inserting elements to map)
    name_age_map.insert({ "Ron",45 });
    name_age_map.insert(pair<string, int>("Susan",14));
    name_age_map.emplace(std::make_pair("Amy", 36));
    name_age_map.insert({ {"Mike",22},{"Rubin",32} });

    cout << "\nAfter adding more elements:\n";

    // print each element again
    for (const auto& elem : name_age_map) {
        cout << elem.first << ": " << elem.second << endl;
    }
}
