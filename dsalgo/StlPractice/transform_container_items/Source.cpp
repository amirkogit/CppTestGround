// Reference: C++17 STL Cookbook
// Transform the content of containers
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };

	transform(begin(v), end(v),
		ostream_iterator<int>{cout, " "},
		[](int i) { return i * i; });
	cout << '\n';

	auto int_to_string([](int i) {
		stringstream ss;
		ss << i << "^2 = " << i * i << '\n';
		return ss.str();
	});

	vector<string> vs;
	transform(begin(v), end(v), back_inserter(vs), int_to_string);
	copy(begin(vs), end(vs), ostream_iterator<string>{cout, " " });

	getchar();
	return 0;
}