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
#include <regex>

// other includes
#include "..\src\common_utilities.h"

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

//////////////////////////////////////////////////////////////////////////////////////
// Day 8 - Dictionaries and maps
void Day8DictionariesAndMaps()
{
    // read total no of entries
    int no_of_entries;
    cin >> no_of_entries;

    cin.ignore();

    // read all entries
    map<string, long> phone_book;
    string name;
    long phone_no;
    for (int i = 0; i < no_of_entries; i++) {
        cin >> name;
        cin >> phone_no;
        phone_book.insert(pair<string, long>(name, phone_no));
    }

#if 0
    for (auto elem : phone_book) {
        cout << elem.first << " = " << elem.second << endl;
}
#endif // 0

    // process queries
    while (cin >> name) {
        if (phone_book.find(name) != phone_book.end()) {
            cout << name << "=" << phone_book.find(name)->second << endl;
        }
        else {
            cout << "Not found" << endl;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void Day10BinaryNumbers()
{
    // method 2
    int n;
    cin >> n;

    int remainder = 0, sequence_counter = 0, max_one_till_now = 0;

    while (n > 0) {
        remainder = n % 2;
        n = n / 2;
        if (remainder == 1){
            sequence_counter++;
            if (sequence_counter >= max_one_till_now)
                max_one_till_now = sequence_counter;
        }
        else {
            sequence_counter = 0;
        }
    }

    cout << max_one_till_now;

    // method 1 (failed testcase 2 and 3)
#if 0
    int n;
    cin >> n;

    stack<int> bin_no;

    while (n > 0) {
        int remainder = n % 2;
        n = n / 2;
        bin_no.push(remainder);
    }

    stack<int> sequence_tracker;
    int max_one_till_now = -1;

    while (!bin_no.empty()) {
        int cur_digit = bin_no.top();
        bin_no.pop();

        if (cur_digit == 1) {
            sequence_tracker.push(cur_digit);
        }
        else {
            // zero encountered
            int count = 0;
            while (!sequence_tracker.empty()) {
                count++;
                sequence_tracker.pop();
            }
            if (max_one_till_now < count) {
                max_one_till_now = count;
            }
        }
    }

    // print the count
    cout << max_one_till_now;
#endif // 0
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void Day112DArrays()
{
    vector< vector<int> > arr(6, vector<int>(6));
    for (int arr_i = 0; arr_i < 6; arr_i++) {
        for (int arr_j = 0; arr_j < 6; arr_j++) {
            cin >> arr[arr_i][arr_j];
        }
    }

    vector<int> sum_list;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                arr[i + 1][j + 1] +
                arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            sum_list.push_back(sum);
        }
    }

    // sort the vector of sum
    sort(sum_list.begin(), sum_list.end(),std::greater<int>());

    cout << sum_list.at(0);

#if 0
    CommonUtilities::PrintElements(sum_list);
#endif // 0
   
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// bubble sort
void Day20Sorting()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    int total_number_of_swaps = 0;

    for (int i = 0; i < n; i++) {
        int number_of_swaps = 0;

        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                number_of_swaps++;
            }
        }

        total_number_of_swaps += number_of_swaps;

        if (number_of_swaps == 0) {
            break;
        }
    }

    cout << "Array is sorted in " << total_number_of_swaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
    
    CommonUtilities::PrintElements(a, "sorted array:");
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// time and complexity (checking prime)
// complexity O(sqroot(n))

namespace Primailty {
    bool IsPrime(int n) {
        int sqroot = sqrt(n);
        if (n  < 2) return false;
        for (int i = 2; i < sqroot; i++) {
            if (n%i == 0) {
                return false;
            }
        }
        return true;
    }

    void Day25CheckPrime()
    {
        int t;
        cin >> t;

        std::vector<int> num;
        num.reserve(t);
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            num.push_back(n);
        }

        for (auto elem : num) {
            if (IsPrime(elem)) {
                cout << "Prime" << endl;
            }
            else {
                cout << "Not prime" << endl;
            }
        }
    }
} // end of namespace
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void Day26NestedLogic()
{
    int returned_day;
    cin >> returned_day;
    int returned_month;
    cin >> returned_month;
    int returned_year;
    cin >> returned_year;

    // read the expected dd//mm//yy
    int expected_day;
    cin >> expected_day;
    int expected_month;
    cin >> expected_month;
    int expected_year;
    cin >> expected_year;

    // check differences
    int year_diff = expected_year - returned_year;
    int month_diff = expected_month - returned_month;
    int day_diff = expected_day - returned_day;

    // calculate fine

    int fine = 0;

    if (returned_year == expected_year) {
        if (returned_month == expected_month) {
            if (returned_day > expected_day) {
                fine = (returned_day - expected_day) * 15;
            }
        }
        else if (returned_month > expected_month) {
            fine = (returned_month - expected_month) * 500;
        }
    }
    else if (returned_year > expected_year) {
        fine = 10000;
    }

    cout << fine;
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void Day28RegularExpressions()
{
    int N;
    cin >> N;
    
    regex re(".+@gmail\\.com");
    vector<string> filtered_names;

    for (int a0 = 0; a0 < N; a0++) {
        string firstName;
        string emailID;
        cin >> firstName >> emailID;

        if (regex_match(emailID, re)) {
            filtered_names.push_back(firstName);
        }
    }

    // sort the names
    sort(filtered_names.begin(), filtered_names.end());

    for (const auto& elem : filtered_names) {
        cout << elem << endl;
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

    //Day6LetsReview();

    //Day8DictionariesAndMaps();

    //Day10BinaryNumbers();

    //Day112DArrays();

    //Day20Sorting();

    //Primailty::Day25CheckPrime();

    //Day26NestedLogic();

    Day28RegularExpressions();
}

