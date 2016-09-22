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
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void UnExpected()
{
    int a{ 4 }, b{ 5 };
    swap(a, b);

    vector<int> evens{ 2,4,6,8, 10 };
    vector<int> odds{ 1,3,5,7,9 };

    auto v1 = evens;
    swap(v1[0], v1[1]);
    iter_swap(begin(v1), begin(v1) + 1);

    auto v2 = odds;
    swap(v1[0], v2[0]);
    iter_swap(begin(v1), find(begin(v2), end(v2), 5));

    v1 = evens;
    v2 = odds;

    swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2));

    vector<int> tasks(6);
    iota(begin(tasks), end(tasks), 1);

    auto two = std::find(begin(tasks), end(tasks), 2);
    auto four = std::find(begin(tasks), end(tasks), 4);
    rotate(two, four, four + 1);

    vector<int> numbers(8);
    iota(begin(numbers), end(numbers), 1);
    auto selected = std::stable_partition(begin(numbers), end(numbers), [](int i) {return i % 2 != 0; });
    four = std::find(begin(numbers), end(numbers), 4);
    rotate(begin(numbers), selected, four);
}

void STLAlgorithms::RunModule7Demo()
{
    UnExpected();
}