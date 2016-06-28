/*
* Solutions to Hackerrank challenges
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

#include "hacker_rank_challenges.h"

// standard library header includes
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <cassert>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////
// Format for defining methods for each coding challenges
// Method name: Title of the problem statement
//              For example, if the problem statement title is "For Loop" in the subdomain Introduction,
//              method name will be IntroForLoop()
// To test call these methods from the method "RunAllDemos()"
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
void IntroHelloWorld()
{
    std::cout << "Hello World";
}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////

void IntroForLoop()
{
    // You will be given two positive integers, a and b (), separated by a newline.
    int a, b;
    cin >> a;
    cin >> b;

    map<int, string> digit_word_map;
    digit_word_map.insert(pair<int, string>(1, "one"));
    digit_word_map.insert(pair<int, string>(2, "two"));
    digit_word_map.insert(pair<int, string>(3, "three"));
    digit_word_map.insert(pair<int, string>(4, "four"));
    digit_word_map.insert(pair<int, string>(5, "five"));
    digit_word_map.insert(pair<int, string>(6, "six"));
    digit_word_map.insert(pair<int, string>(7, "seven"));
    digit_word_map.insert(pair<int, string>(8, "eight"));
    digit_word_map.insert(pair<int, string>(9, "nine"));

    for (int i = a; i <= b; i++) {
        // for all the integers in the range [a,b],print the english representation of it
        if (i >= 1 && i <= 9) {
            // print the english representation of it
            auto result = digit_word_map.find(i);
            string s = result->second;
            cout << s.c_str() << endl;
        }
        else {
            // if the number is even, print even otherwise print odd
            if (i % 2 == 0) {
                cout << "even\n";
            }
            else {
                cout << "odd\n";
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

// Introduction/Functions
// *****************************

//Add `int max_of_four(int a, int b, int c, int d)` here.
int max_of_four(int a, int b, int c, int d)
{
    vector<int> list = { a,b,c,d };
    auto max = std::max_element(list.begin(), list.end());
    return *max;
}

void IntroFunction()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    vector<int> list;
}

///////////////////////////////////////////////////////////

// Introduction/Pointer
void update(int *a, int *b) {
    // Complete this function    
    int tempa = *a;
    int tempb = *b;
    *a = tempa + tempb;
    *b = std::abs(tempa - tempb);
}

void IntroPointer()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}

///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Introduction/Arrays
void IntroArrays()
{
    int n; // size of array
    cin >> n;

    assert(!(n < 1 || n > 1000));

    vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    // reverse the vector contents
    std::reverse(arr.begin(), arr.end());

    // print the contents
    for (auto elem : arr) {
        cout << elem << " ";
    }
}

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Introduction/Preprocessor solution
// Sample solution
#define toStr(str) #str

#define io(data) cin >> data

#define foreach(arr, idx) \
for(int idx = 0; idx < arr.size(); idx++)

#define FUNCTION(name, op) \
void name(int &x, int y)\
{ \
    if(!(x op y)) \
        x = y;\
}

#define INF 1e9

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

void IntroPreprocessor()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }

    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
}
///////////////////////////////////////////////////////////

void HackerRankChallenges::RunDomainCppChallenges()
{
    std::cout << "Running all C++ domain challenges." << endl;

    //IntroHelloWorld();

    //IntroForLoop();

    //IntroFunction();

    //IntroPointer();

    //IntroArrays();

    //IntroPreprocessor();
}



