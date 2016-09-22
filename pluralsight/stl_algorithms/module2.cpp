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

void Count()
{
    vector<int> v{ 2,7,1,6,2,-2,4,0 };

    //count how many entries have the target value (2)
    int twos = 0;
    int const target = 2;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            twos++;
        }
    }

    twos = count(v.begin(), v.end(), target);
    twos = count(begin(v), end(v), target);

    //count how many entries are odd
    int odds = 0;
    for (auto elem : v)
    {
        if (elem % 2 != 0)
        {
            odds++;
        }
    }

    odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

    map<int, int> monthlengths{ { 1,31 },{ 2,28 },{ 3,31 },{ 4,30 },{ 5,31 },{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 } };
    int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) {return elem.second == 31; });

    //are all, any, or none of the values odd? (Conclude from number of odd entries)
    bool allof, noneof, anyof;
    allof = (odds == v.size());
    noneof = (odds == 0);
    anyof = (odds > 0);

    allof = all_of(begin(v), end(v),
        [](auto elem) {return elem % 2 != 0; });
    noneof = none_of(begin(v), end(v),
        [](auto elem) {return elem % 2 != 0; });
    anyof = any_of(begin(v), end(v),
        [](auto elem) {return elem % 2 != 0; });
}

void Find()
{
    vector<int> v{ 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
    string s{ "Hello I am a sentence" };

    //find the first zero in the collection
    auto result = find(begin(v), end(v), 0);
    int weLookedFor = *result;

    //find the first 2 after that zero
    result = find(result, end(v), 2);
    if (result != end(v))
    {
        weLookedFor = *result;
    }

    //find the first a
    auto letter = find(begin(s), end(s), 'a');
    char a = *letter;

    //find first odd value
    result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
    weLookedFor = *result;

    //find first even value
    result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
    weLookedFor = *result;

    vector<int> primes{ 1,2,3,5,7,11,13 };
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    weLookedFor = *result;

    vector<int> subsequence{ 2,4 };
    result = search(begin(v), end(v), begin(subsequence), end(subsequence));
    weLookedFor = *result;
    result++; result++;
    int six = *result;

    string am = "am";
    letter = search(begin(s), end(s), begin(am), end(am));
    a = *letter;

    result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
    result++; result++;
    if (result != end(v))
    {
        weLookedFor = *result;
    }

    result = search_n(begin(v), end(v), 2, 4);
    result--;
    int two = *result;

    result = adjacent_find(begin(v), end(v));
    six = *result;
    result++;
    six = *result;
}
void STLAlgorithms::RunModule2Demo()
{
    Count();

    Find();
}