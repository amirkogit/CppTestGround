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
#include <string>

using namespace std;

void Comparing()
{
    vector<int> a{ 1, 2, 3, 4 , 5 };
    vector<int> b{ 1, 2, 0, 4 };

    bool same = a.size() == b.size();
    for (size_t i = 0; i < a.size() && same; i++)
    {
        if (a[i] != b[i])
        {
            same = false;
        }
    }

    same = equal(begin(a), end(a), begin(b), end(b));

    auto firstchange = mismatch(begin(a), end(a), begin(b));

    int avalue = *(firstchange.first);
    int bvalue = *(firstchange.second);
    auto distance = firstchange.first - begin(a);

    int total = 0;
    for (int i : a)
    {
        total += i;
    }

    total = accumulate(begin(a), end(a), 0);
    total = accumulate(begin(a), end(a), 0,
        [](int total, int i) {if (i % 2 == 0) return total + i; return total; });
    total = accumulate(begin(a), end(a), 1,
        [](int total, int i) {return total * i; });

    vector<string> words{ "one","two","three" };
    auto allwords = accumulate(begin(words), end(words), string{});
    int length = allwords.size();
    allwords = accumulate(begin(words), end(words), string{ "Words:" }, [](const string& total, string& s) {return total + " " + s; });
    length = allwords.size();

    string s = accumulate(begin(a), end(a), string{ "The numbers are:" },
        [](const string& total, int i) {return total + " " + to_string(i); });

    b = a;
    for (auto it = begin(b); it != end(b); it++)
    {
        *it = 0;
    }

    for (auto& i : b)
    {
        i = 1;
    }

    for_each(begin(b), end(b), [](int& elem) {elem = 2; });

    b = a;
    auto firstthree = find(begin(b), end(b), 3);
    for_each(firstthree, end(b), [](int& elem) {elem = 0; });
}

void STLAlgorithms::RunModule4Demo()
{
    Comparing();
}