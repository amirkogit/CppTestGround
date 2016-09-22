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
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>
#include <array>

using namespace std;


void Iterators()
{
    vector<int> v1(10);
    fill(begin(v1), end(v1), 1);
    fill_n(begin(v1), 6, 2);
    iota(begin(v1), end(v1), 1);

    vector<int> v2;
    fill_n(back_inserter(v2), 6, 2);
    generate_n(back_inserter(v2), 10, [n = 0]()mutable{return n++; });

    deque<int> q3;
    fill_n(front_inserter(q3), 6, 2);
    generate_n(front_inserter(q3), 10, [n = 0]()mutable{return n++; });

    //fill_n(front_inserter(v1), 6, 2);

    v2.clear();
    transform(begin(v1), end(v1), back_inserter(v2),
        [](int elem) {return elem * 2; });

    vector<int> v3{ 3, 6, 1, 0, -2, 5 };
    vector<int> v5;
    copy_if(begin(v3), end(v3), back_inserter(v5),
        [](int elem) {return elem % 2 == 0; });

    v3[3] = -2;
    vector<int> v6;
    unique_copy(begin(v3), end(v3), back_inserter(v6));

    string sentence = "Hello, world!";
    string reverse;
    reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));

    v2.clear();
    copy(rbegin(v1), rend(v1), back_inserter(v2));

    v1[5] = 2;
    auto two = find(begin(v1), end(v1), 2);
    auto distance = two - begin(v1);
    two++;

    auto rtwo = find(rbegin(v1), rend(v1), 2);
    distance = rtwo - rbegin(v1);
    rtwo++;

    //distance = rtwo - two;

    //is "3" in the first or second half?
    auto three = find(begin(v1), end(v1), 3);
    bool firsthalf = (three - begin(v1) < end(v1) - three);
    //What about "9" ?
    auto nine = find(begin(v1), end(v1), 9);
    firsthalf = (nine - begin(v1) < end(v1) - nine);

    array<const int, 5> ca = { 3,1,6,0,2 };
    auto it = begin(ca);
    it++;
    //*it = 7;
    int i = *it;

    //vector<const int> vc;

    it = find(begin(ca), end(ca), 1);
    it++;
    //*it = 7;
    //it = cbegin(ca);

    auto it2 = begin(v2);
    it2++;
    *it2 = 7;

    auto cit = cbegin(v2);
    cit++;
    //*cit = 7;
}

void STLAlgorithms::RunModule6Demo()
{
    Iterators();
}