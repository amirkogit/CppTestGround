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


// 30 days coding challenge
//////////////////////////////////////////////////////////////////////////////////////
// Day 1: data types
void Day1DataTypes()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int i2;
    double d2 = 0.0;
    string s2;

    // Read and save an integer, double, and String to your variables.
    cin >> i2;
    cin >> d2;
    cin.ignore(); // ignore any newline character, can also use getchar()
    getline(cin, s2);

    // Print the sum of both integer variables on a new line.
    cout << i + i2 << endl;

    // Print the sum of the double variables on a new line.
    double result = (double)d + d2;
    cout.precision(1);
    cout << fixed <<result << endl; // here using std::fixed is necessary to correctly output 4.0 + 8.0 = 12.0, ot

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + s2;

}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// Day2 operators
void Day2Operators()
{
    //There are  lines of numeric input :
    //The first line has a double, mealCost(the cost of the meal before tax and tip).
    //The second line has an integer, tipPercent (the percentage of  being added as tip).
    //The third line has an integer, taxPercent (the percentage of  being added as tax).

    // Output:
    //Print The total meal cost is totalCost dollars., where  is the rounded integer result of the entire bill(with added tax and tip).

    double mealCost{ 0.0 };
    int tipPercent{ 0 };
    int taxPercent{ 0 };

    cin >> mealCost;
    cin >> tipPercent;
    cin >> taxPercent;

    double tip = mealCost * ((double)tipPercent / 100);
    double tax = mealCost * ((double)taxPercent / 100);

    double totalCost = mealCost + tip + tax;
    //int totalCostRounded = (int)totalCost;

    cout << "The total meal cost is " << std::round(totalCost) << " dollars.";
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// Day 3 Intro to conditional statements
void Day3ConditionalStatements()
{
    int n;
    cin >> n;

    if (n % 2 != 0) {
        // number is odd
        cout << "Weird";
    }
    else {
        // number is even
        if (n >= 2 && n <= 5) {
            cout << "Not Weird";
        }
        else if (n >= 6 && n <= 20) {
            cout << "Weird";
        }
        else if (n > 20) {
            cout << "Not Weird";
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// Day5 Loops
void Day5Loops()
{
    int n;
    cin >> n;

    if (n >= 2 && n <= 20) {
        for (int i = 1; i <= 10; i++) {
            cout << n << " x " << i << " = " << n*i << endl;
        }
    }

}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// Day 6 : review
void Day6LetsReview()
{
    int n; // total test cases
    cin >> n;
    cin.ignore();

    assert((n >= 1 && n <= 10));

    vector<string> input_strings;

    // read strings
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s.length() >= 2 && s.length() <= 10000) {
            input_strings.push_back(s);
        }
    }

    // print the contents of input strings
#if 0
    cout << endl;
    for (auto elem : input_strings) {
        cout << elem << endl;
    }
#endif // 0

    for (auto elem : input_strings) {
        string s = elem;
        int idx = 0;
        vector<char> s_even;
        vector<char> s_odd;
        for (auto ch : s) {
            if (idx % 2 == 0 || idx == 0) {
                // even
                s_even.push_back(ch);
            }
            else {
                // odd
                s_odd.push_back(ch);
            }
            idx++;
        }

        // print even indexed characters
        for (auto e : s_even) {
            cout << e;
        }

        // print space
        cout << " ";

        // print odd indexed characters
        for (auto e : s_odd) {
            cout << e;
        }

        // newline
        cout << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////


void HackerRankChallenges::Run30DayChallenges()
{
    std::cout << "Running all 30 day challenges." << endl;

    //Day1DataTypes();

    //Day2Operators();

    //Day3ConditionalStatements();

    //Day5Loops();

    Day6LetsReview();

}

