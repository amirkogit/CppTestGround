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
// World CodeSprint#4 Minimum distance
void WorldCodeSprint4MinimumDistance()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    std::vector<int> results;

    // store each value in the map
    std::map<int, int> value_index_map;

    for (int i = 0; i < A.size(); ++i) {
        int index = i;
        int val = A.at(i);

        int abs_diff = 0;

        auto findval = value_index_map.find(val);
        if (findval != value_index_map.end()) {
            // get the previously stored index value
            int prev_idx = findval->second;

            // store the absolute difference
            abs_diff = std::abs(prev_idx - index);

            results.push_back(abs_diff);

            //value_index_map.insert(std::pair<int, int>(A.at(i), abs_diff));
        }
        else {
            // first time insert
            value_index_map.insert(std::pair<int, int>(A.at(i), index));
        }
    }

    sort(results.begin(), results.end(),std::less<int>());

    // sort the values of results
    //for (auto elem : results) {
    //    cout << elem;
    //}

    int min_distance = -1;
    if (results.size() > 0) {
        min_distance = results.at(0);
    }
    cout << min_distance;
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// World CodeSprint#4 Equal stacks

int GetStackHeight(std::stack<int> in_stack)
{
    int height{0};
    while (!in_stack.empty()) {
        height += in_stack.top();
        in_stack.pop();
    }
    return height;
}

void WorldCodeSprint4EqualStacks()
{
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for (int h1_i = 0; h1_i < n1; h1_i++) {
        cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for (int h2_i = 0; h2_i < n2; h2_i++) {
        cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for (int h3_i = 0; h3_i < n3; h3_i++) {
        cin >> h3[h3_i];
    }

    // define three stacks
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::stack<int> stack3;

    std::vector<std::pair<int,int>> stack_heights(3);

    // insert the input items into respective stacks
    for (auto iter = h1.rbegin(); iter != h1.rend(); ++iter) {
        stack1.push(*iter);
    }

    for (auto iter = h2.rbegin(); iter != h2.rend(); ++iter) {
        stack2.push(*iter);
    }

    for (auto iter = h3.rbegin(); iter != h3.rend(); ++iter) {
        stack3.push(*iter);
    }

    // check if the heights of all stacks are same
    bool all_same_height = false;
    int final_height = 0;
    while (!all_same_height){
        // 1. check the heights of all stacks
        // 2. if all heights are equal, break the loop
        // 3. if not, find the stack with the max height
        // 4. pop the element from that stack
        // 5. repeat from 1
        int ht1 = GetStackHeight(stack1);
        int ht2 = GetStackHeight(stack2);
        int ht3 = GetStackHeight(stack3);
        stack_heights.clear();
        stack_heights.push_back(std::make_pair(1, ht1));
        stack_heights.push_back(std::make_pair(2, ht2));
        stack_heights.push_back(std::make_pair(3, ht3));

        if ((ht1 == ht2) && (ht2 == ht3)) {
            all_same_height = true;
            final_height = ht1;
            break;
        }
        else {
            int max_height = std::max({ ht1,ht2,ht3 });

            // find which of the stack has the max height
            int stack_num = 0;
            for (auto elem : stack_heights) {
                if (elem.second == max_height) {
                    stack_num = elem.first;
                }
            }

            if (stack_num == 1) {
                stack1.pop();
            }
            else if (stack_num == 2) {
                stack2.pop();
            }
            else if (stack_num == 3) {
                stack3.pop();
            }
        }
    }

    cout << final_height;
}
//////////////////////////////////////////////////////////////////////////////////////

namespace RookieRank {
    void BirthDayCakeCandles() {
        int no_of_candles;
        cin >> no_of_candles;

        std::map<int, int> map_height_count;

        for (int i = 0; i < no_of_candles; i++) {
            int h;
            cin >> h;
            map_height_count[h] = map_height_count[h] + 1;
        }

        auto pos = max_element(map_height_count.begin(), map_height_count.end());
        cout << pos->second;
    }

    void CountingValleys() {
        int no_of_steps;
        cin >> no_of_steps;

        cin.ignore();
        std::string steps;
        cin >> steps;

        int no_of_valleys = 0;
        int sea_level = 0;

        bool valley_count_started = false;

        for (auto c : steps) {
            // record for valleys if below sea level
            if (sea_level == 0 && (c == 'D' || c == 'd')) {
                valley_count_started = true;
            }


            if (c == 'D' || c == 'd') {
                sea_level--;
            }
            else if (c == 'U' || c == 'u') {
                sea_level++;
            }
            //cout << "sea level value: " << sea_level << endl;

            if (sea_level == 0 && (c == 'U' || c == 'u') && valley_count_started) {
                no_of_valleys++;
                valley_count_started = false; // reset
            }
        }

        cout << no_of_valleys;
    }

    bool CheckForMagicSquare(const vector<vector<int>>& matrix) {
        return true;
    }

    void MagicSquareForming() {
        const int MAGIC_CONSTANT = 15;

        // read input
        vector<vector<int>> magic_square;

        for (int i = 0; i < 3; i++) {
            vector<int> row;
            for (int j = 0; j < 3; j++) {
                int n;
                cin >> n;
                row.push_back(n);
            }
            magic_square.push_back(row);
        }

#if 0
        // print matrix
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << magic_square[i][j] << " ";
            }
            cout << endl;
        }
#endif // 0

        int min_cost = 0;
        bool is_magic_square = false;

        while(!is_magic_square) {
            if (CheckForMagicSquare(magic_square)) {
                is_magic_square = true;
            }
            else {
                // rearrange elements and calculate cost
            }
        }

        cout << min_cost;
    }

}// end of namespace RookieRank
//////////////////////////////////////////////////////////////////////////////////////

void HackerRankChallenges::RunWorldCodeSprint4Challenges()
{
    std::cout << "Running all Code Sprint 4 challenges." << endl;

    //WorldCodeSprint4MinimumDistance();

    //WorldCodeSprint4EqualStacks();

    //RookieRank::BirthDayCakeCandles();

    //RookieRank::CountingValleys();

    RookieRank::MagicSquareForming();
}