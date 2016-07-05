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

namespace DynamicArrays {
    enum class QueryType {
        Type_1 = 1,
        Type_2
    };

    struct Query {
        int type;
        int x;
        int y;
    };

    void DynamicArrays()
    {
        // read number of sequences
        int no_of_sequences{ 0 };
        cin >> no_of_sequences;

        // read number of queries
        int no_of_queries;
        cin >> no_of_queries;

        vector<Query> query_list;

        // read all queries
        for (int idx_query = 0; idx_query < no_of_queries; idx_query++) {
            Query q;
            cin >> q.type;
            cin >> q.x;
            cin >> q.y;
            query_list.push_back(q);
        }

        // last answer variable
        int last_answer{ 0 };

        // create empty sequences
        vector<vector<int>> seq_list(no_of_sequences);

        // execute all queries from the query list
        for (auto elem : query_list) {
            QueryType type = static_cast<QueryType>(elem.type);

            if (type == QueryType::Type_1) {
                // find the sequence index
                int seq_idx = (elem.x ^ last_answer) % no_of_sequences;

                // append integer y to the sequence seq
                seq_list[seq_idx].push_back(elem.y);
            }
            else if (type == QueryType::Type_2) {
                // find the sequence index
                int seq_idx = (elem.x ^ last_answer) % no_of_sequences;

                last_answer = elem.y % (seq_list[seq_idx].size());

                cout << seq_list[seq_idx][last_answer] << endl;

                last_answer = seq_list[seq_idx][last_answer];
            }
        }
    }
} // end of namespace DynamicArrays

void HackerRankChallenges::RunDomainDataStructuresChallenges()
{
     std::cout << "Running all data structures domain challenges. " << endl;

     DynamicArrays::DynamicArrays();
}



