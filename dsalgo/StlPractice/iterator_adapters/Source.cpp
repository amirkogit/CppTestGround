// Reference: C++17 STL Cookbook
// Iterator adapters demo
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <deque>

using namespace std;

int main()
{
	cout << "Enter numbers followed by spaces. Type any character to end and press ENTER.\n";

	istream_iterator<int> it_cin{ std::cin };
	istream_iterator<int> end_cin;

	deque<int> v;
	copy(it_cin, end_cin, back_inserter(v));

	// print the numbers entered so far
	copy(begin(v), end(v), ostream_iterator<int> { cout, " "});
	cout << endl;

	istringstream sstr{ "123 456 789" };

	auto deque_middle(next(begin(v),
		static_cast<int>(v.size()) / 2));

	copy(istream_iterator<int>{sstr}, {}, inserter(v, deque_middle));

	initializer_list<int> il2{ -1,-2,-3 };
	copy(begin(il2), end(il2), front_inserter(v));

	// print the numbers entered so far
	copy(begin(v), end(v),
		ostream_iterator<int> {cout, ", "});
	cout << '\n';

	getchar();
	return 0;
}
