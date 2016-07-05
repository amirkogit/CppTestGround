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

// other includes
#include "..\src\common_utilities.h"

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////
// Algorithms/Warmup/PlusMinus
void WarmupPlusMinus()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
        cin >> arr[arr_i];
    }

#if 0
    // print the content of vector
    CommonUtilities::PrintElements(arr, "Input numbers");
#endif // 0

    int count_pos_no{ 0 };
    int count_neg_no{ 0 };
    int count_zero_no{ 0 };

    for (auto elem : arr) {
        if (elem == 0) {
            count_zero_no++;
        }
        else if (elem > 0) {
            // positive number
            count_pos_no++;
        }
        else if (elem < 0) {
            // negative number
            count_neg_no++;
        }
    }

    int total_no = arr.size();

    double frac_pos_no = count_pos_no / (double)total_no;
    double frac_neg_no = count_neg_no / (double)total_no;
    double frac_zero_no = count_zero_no / (double)total_no;

    std::setprecision(6);
    cout << fixed << frac_pos_no << endl;
    cout << fixed << frac_neg_no << endl;
    cout << fixed << frac_zero_no << endl;
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// // Algorithms/Warmup/Staircase
void WarmupStaircase()
{
    int n;
    cin >> n;

    vector<vector<char>> staircase;

    int no_of_tiles = 1;
    for (int i = 0; i < n; i++, no_of_tiles++) {
        // create steps
        vector<char> step;

        // fill first few with spaces
        for (int i = 0; i < (n - no_of_tiles); i++) {
            step.push_back(' ');
        }

        // fill the rest with #
        for (int i = 0; i < no_of_tiles; i++) {
            step.push_back('#');
        }

        // add individual step
        staircase.push_back(step);
    }

    // print staircase in reverse order
    for (auto elem : staircase) {
        for (auto step : elem) {
            cout << step;
        }
        cout << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void ImplDivisibleSumPairs()
{
    // read size of array
    int n;
    cin >> n;

    // read positive integer k (number to test for evenly divisibility)
    int k;
    cin >> k;

    vector<int> arr(n);

    // read all numbers
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
#if 0
            cout << "(" << i << "," << j << "):" << arr[i] << "+" << arr[j] << " = " << arr[i] + arr[j] << endl;
#endif // 0
            if (((arr[i] + arr[j]) % k) == 0) {
                count++;
            }
        }
    }

    cout << count;
}
//////////////////////////////////////////////////////////////////////////////////////

void HackerRankChallenges::RunDomainAlgorithmsChallenges()
{
    std::cout << "Running all algorithm domain challenges." << endl;

    //WarmupPlusMinus();

    //WarmupStaircase();

    ImplDivisibleSumPairs();
}



