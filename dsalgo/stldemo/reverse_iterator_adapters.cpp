// Reference: C++17 STL Cookbook
// Demo of reverse iterator adapters
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <iterator>

#if 1
using namespace std;

int main()
{
    list<double> l1 {3.14,2.7,3.55,8.6,9.14,2.14};

    cout << "Original list\n";
    copy(l1.begin(), l1.end(), ostream_iterator<double> {cout, " "});
    cout << "\n";

    cout << "List in reverse order\n";
    copy(l1.rbegin(), l1.rend(), ostream_iterator<double> {cout, " "});
    cout << "\n";

    list<int> l2 {1,2,3,4,5,6};
    cout << "List in original order\n";
    copy(l2.begin(), l2.end(), ostream_iterator<int> {cout, " "});
    cout << "\n";

    cout << "List in reverse iterator using: make_reverse_iterator\n";
    copy(make_reverse_iterator(end(l2)),
         make_reverse_iterator(begin(l2)),
         ostream_iterator<int> {cout, " "});
    cout << "\n";

    return 0;
}
#endif
