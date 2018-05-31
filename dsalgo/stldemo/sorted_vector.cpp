//-----------------------------------------------------------------------------------------
// Demonstrates the usage of sorted vector
// Reference: C++17 STL Cookbook
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

#if 0

template <typename C>
void display_elements(const C& v, const std::string& header)
{
    cout << header << "\n";

    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << "\n\n";
}

template<typename C, typename T>
void insert_sorted(C& v, const T& item)
{
    const auto insert_pos (lower_bound(begin(v), end(v), item));
    v.insert(insert_pos, item);

    std::stringstream ss;
    ss << "Insert-> " << item;
    display_elements(v,ss.str());
}

int main()
{
    vector<string> states {"california", "alaska", "florida", "georgia", "newyork", "utah", "nebraska", "las vegas"};
    display_elements(states, "Initial unsorted list");

    // initially the vector of states is not sorted
    assert(false == is_sorted(begin(states), end(states)));

    // sort using algorithm sort
    sort(begin(states),end(states));
    assert(true == is_sorted(begin(states), end(states)));
    display_elements(states, "Sorted list");

    insert_sorted(states, "iowa");
    insert_sorted(states, "illinois");
    insert_sorted(states, "maryland");

    return 0;
}
#endif

