// Reference: C++17 STL Cookbook
// Copying items from containers to other containers
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <iterator>
#include <algorithm>

using namespace std;

namespace std {
	ostream& operator<<(ostream& os, const pair<int, string>& p)
	{
		return os << "(" << p.first << ", " << p.second << ")";
	}
}

int main()
{
	auto shell_it(ostream_iterator<pair<int, string>> 
	{ cout, ", "});

	vector<pair<int, string>> v{
		{1, "one"}, {2, "two"}, {3, "three"},
		{4, "four"}, {5, "five"}
	};

	cout << "Contents of v:";
	copy(begin(v), end(v), shell_it);
	cout << "\n";

	map<int, string> m;
	copy_n(begin(v), 4, inserter(m, begin(m)));

	cout << "Contents of m:";
	copy(begin(m), end(m), shell_it);
	cout << "\n";

	m.clear();
	cout << "Contents of m:";
	copy(begin(m), end(m), shell_it);
	cout << "\n";

	move(begin(v), end(v), inserter(m, begin(m)));

	cout << "Contents of m(after move): ";
	copy(begin(m), end(m), shell_it);
	cout << "\n";

	cout << "Contents of v(after move): ";
	copy(begin(v), end(v), shell_it);
	cout << "\n";

	// copy v to different container after move operation has been performed
	auto v2 = v;
	v2.push_back(make_pair(7, "seven"));

	cout << "Contents of v2: ";
	copy(begin(v2), end(v2), shell_it);
	cout << "\n";

	
	getchar();
	return 0;
}