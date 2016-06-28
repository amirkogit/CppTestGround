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
// Week of code 21 challenges
void WeekOfCode21Kangaroo()
{
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

    // constraints check
    if (x1 < 0 || x1 > x2 || x1 > 10000 || x2 > 10000) {
        cout << "NO";
        return;
    }
    if (v1 < 1 || v1 > 10000) {
        cout << "NO";
        return;
    }
    if (v2 < 1 || v2 > 10000) {
        cout << "NO";
        return;
    }

    if (x2 > x1 && v2 > v1) {
        cout << "NO";
        return;
    }

    int trial = 0;
    bool found = false;
    for (trial = 0; trial <= 10000; trial++) {
        x1 += v1;
        x2 += v2;

        if (x1 == x2) {
            cout << "YES";
            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "NO";
    }
}
//////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// Week of code 21 challenges - Luck balance
void WeekOfCode21LuckBalance()
{
    // N = number of preliminary contests
    // K = maximum number of important contests that Lena can lose
    // L = contest luck balance
    // T = contest important rating (0 or 1)
    int N, K, L, T;

    // constraints
    // 1 <= N <= 100
    // 0 <= K <= N
    // 1 <= L <= 10000
    // 0 <= T <= 1

    vector<int> imp_contests;
    vector<int> uimp_contests;

    // read contest numbers and max contest that can be lost
    cin >> N >> K;
    assert(!(N < 1 || N > 100));
    assert(!(K < 0 || K > N));

    for (int i = 0; i < N; i++) {
        int luck_balance = -1;
        cin >> luck_balance;
        assert(!(luck_balance < 1 || luck_balance > 10000));

        int contest_importance = -1;
        cin >> contest_importance;
        assert(!(contest_importance < 0 || contest_importance > 1));

        if (contest_importance == 1) {
            imp_contests.push_back(luck_balance);
        }
        else if (contest_importance == 0) {
            uimp_contests.push_back(luck_balance);
        }
    }

    // sort the contents of important contests
    std::sort(imp_contests.begin(), imp_contests.end(),std::greater<int>());

#if 0
    // print the contents of vector
    cout << "Contents of important contests: " << endl;
    for (auto elem : imp_contests) {
        cout << elem << endl;
    }

    cout << "Contents of unimportant contests: " << endl;
    for (auto elem : uimp_contests) {
        cout << elem << endl;
    }
#endif // 0

    // calculate the final luck balance by traversing through each elements
    int luck_tracker = 0;
    int final_luck_balance = 0;
    for (auto elem : imp_contests) {
        if (luck_tracker >= K) {
            final_luck_balance -= elem;
        }
        else {
            final_luck_balance += elem;
        }
        luck_tracker++;
    }

    for (auto elem : uimp_contests) {
        final_luck_balance += elem;
    }

    cout << final_luck_balance;
}
/////////////////////////////////////////////////////////

void HackerRankChallenges::RunWeekOfCode21Challenges()
{
    std::cout << "Running all Week of code 21 challenges." << endl;

    WeekOfCode21Kangaroo();

    WeekOfCode21LuckBalance();
}
