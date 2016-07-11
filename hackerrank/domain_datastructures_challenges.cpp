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


//////////////////////////////////////////////////////////////////////////////////////
namespace ArrayLeftRotation {

    void ArrayLeftRotation() 
    {
        // read size of array
        int n;
        cin >> n;

        // read rotation distance
        int d;
        cin >> d;

        assert(d <= n);

        // read all numbers
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

#if 0
        CommonUtilities::PrintElements(arr, "contents of arr");
#endif // 0

        vector<int> new_arr(n);
        int idx = 0;
        for (int i = d; i < arr.size(); i++) {
            new_arr[idx] = arr[i];
            idx++;
        }

        // copy the rest to end
        for (int i = 0; i < d; i++) {
            new_arr[idx] = arr[i];
            idx++;
        }

        for (auto elem : new_arr) {
            cout << elem << " ";
        }
    }
} // end of namespace ArrayLeftRotation
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void ArraysSparseArrays()
{
    // read total size of input string array
    int n; 
    cin >> n;
    cin.ignore();

    // read all strings
    vector<string> string_list;
    string_list.reserve(n);
    for (int i = 0; i < n; i++) {
        string cur_string;
        getline(cin, cur_string);
        string_list.push_back(cur_string);
    }

    // read total query size
    int q; 
    cin >> q;
    cin.ignore();

    // read all queries
    vector<string> query_list;
    query_list.reserve(q);
    for (int i = 0; i < q; i++) {
        string cur_string;
        getline(cin, cur_string);
        query_list.push_back(cur_string);
    }

    //CommonUtilities::PrintElements(string_list, "Input strings..");
    //CommonUtilities::PrintElements(query_list, "Query strings ...");

    // process all queries
    int count = 0;
    for (auto query_string : query_list) {
        for (auto input_string : string_list) {
            if (query_string.compare(input_string) == 0) {
                count++;
            }
        }
        cout << count << endl;
        count = 0; // reset for next usage
    }
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
namespace LinkedList {
    // challenges related to linkedlist

    // Node of a linked list is defined as
    struct Node {
        int data;
        Node* next;
    };

    // print elements of a linked list on console
    void Print(Node* head)
    {
        Node* cur_node = head;

        // traverse each element of a node and print its content
        while (cur_node != nullptr) {
            cout << cur_node->data << endl;
            cur_node = cur_node->next;
        }
    }

    // insert a node at the tail of a linked list
    // returns the head of an updated linked list
    Node* InsertAtTail(Node* head, int data)
    {
        // create a new node
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        Node* cur_node = head;
        if (cur_node == nullptr) {
            head = new_node;
        }
        else {
            cur_node = head;

            // traverse to the tail
            while (cur_node->next != nullptr) {
                cur_node = cur_node->next;
            }

            cur_node->next = new_node;
        }

        return head;
    }
   
    // insert a node at the head of a linked list
    // returns the head of an updated linked list
    Node* InsertAtHead(Node* head, int data)
    {
        // create a new node
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        Node* cur_node = head;

        // check if the list is empty
        if (cur_node == nullptr) {
            head = new_node;
        }
        else {
            Node* before = head;
            head = new_node;
            head->next = before;
        }

        return head;
    }

    // insert a node at specific position in a linked list
    // returns the head of an updated linked list
    Node* InsertAtNth(Node* head, int data, int position)
    {
        // create a new node
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        int count = 0;
        Node* prev_node = nullptr;
        Node* cur_node = head;

        while (cur_node != nullptr && count < position) {
            count++;
            prev_node = cur_node;
            cur_node = cur_node->next;
        }

        if (count != position) {
            cout << "Linked list doesn't contain enough nodes!";
        }
        else {
            if (prev_node == nullptr) {
                // insert at head
                new_node->next = head;
                head = new_node;
            }
            else {
                new_node->next = cur_node;
                prev_node->next = new_node;
            }
        }

        return head;
    }

    // delete a node at a given position in a linked list
    // returns the head of an updated linked list
    Node* DeleteAtNth(Node* head, int position)
    {
        int count = 0;
        Node* prev_node = nullptr;
        Node* cur_node = head;

        while (cur_node != nullptr && count < position) {
            count++;
            prev_node = cur_node;
            cur_node = cur_node->next;
        }

        if (count != position) {
            cout << "Linked list doesn't contain enough nodes!";
        }
        else {
            if (prev_node == nullptr) {
                // delete the head
                Node* temp = cur_node;
                cur_node = cur_node->next;

                // free the node
                delete(temp);

                // update the head node
                head = cur_node;
            }
            else {
                prev_node->next = (prev_node->next)->next;
                    
                // free the node
                delete(cur_node);
            }
        }

        return head;
    }

    // demo to print the data of a single linked list
    void RunLinkedListDemo()
    {
        // Test: 1 inserting node at tail
        {
            cout << "Inserting 2,4,8 in list [1] at tail and printing them." << endl;

            Node* head = new Node;
            head->data = 1;
            head->next = nullptr;

            head = InsertAtTail(head, 2);
            head = InsertAtTail(head, 4);
            head = InsertAtTail(head, 8);

            Print(head);
        }

        // Test: 2 inserting node at head
        {
            cout << endl;
            cout << "Inserting 4,5,20,21 in list [3] at head and printing them" << endl;

            Node* head = new Node;
            head->data = 3;
            head->next = nullptr;

            head = InsertAtHead(head, 4);
            head = InsertAtHead(head, 5);
            head = InsertAtHead(head, 20);
            head = InsertAtHead(head, 21);

            Print(head);
        }

        // Test: 3 inserting node at Nth position
        {
            cout << endl;
            cout << "Inserting 20 in list [5 2 3 8 42] at position 4" << endl;

            Node* head = nullptr;
            head = InsertAtTail(head, 5);
            head = InsertAtTail(head, 2);
            head = InsertAtTail(head, 3);
            head = InsertAtTail(head, 8);
            head = InsertAtTail(head, 42);

            head = InsertAtNth(head, 20, 4);

            Print(head);
        }

        // Test: 4 deleting a node at a given position
        {
            cout << endl;
            cout << "Deleting a node in list [1 3 5 10] at position 0" << endl;

            Node* head = nullptr;
            head = InsertAtTail(head, 1);
            head = InsertAtTail(head, 3);
            head = InsertAtTail(head, 5);
            head = InsertAtTail(head, 20);

            cout << "Before deleting:\n";
            Print(head);

            cout << "\nAfter deleting:\n";
            head = DeleteAtNth(head, 0);

            Print(head);
        }

    }// end of RunLinkedListDemo()

} // end of namespace linkedlist
//////////////////////////////////////////////////////////////////////////////////////

void HackerRankChallenges::RunDomainDataStructuresChallenges()
{
     std::cout << "Running all data structures domain challenges. " << endl;

     //DynamicArrays::DynamicArrays();

     //ArrayLeftRotation::ArrayLeftRotation();

     //ArraysSparseArrays();

     LinkedList::RunLinkedListDemo();
}



