//-----------------------------------------------------------------------------------------
// Demonstrates the erase remove idiom on std::vector
// // Reference: C++17 STL Cookbook
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_vector(const vector<int> v)
{
	cout << "Content: ";
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << "size: " << v.size() << "\n\n";
}

int main()
{
	cout << "Vector erase remove idiom demo" << endl;

	vector<int> v{ 1,2,3,2,5,3,6,2,4,8 };
	display_vector(v);

	// remove 2 from vector
	const auto new_end(remove(begin(v), end(v), 2));
	display_vector(v);

	// erase the element
	v.erase(new_end, end(v));
	display_vector(v);

	vector<int> v2{ 100,33,200,300,101,201,500,788,45,68,77,22 };
	display_vector(v2);

	// define predicate to remove all even items
	const auto even([](int i) { return i % 2 == 0; });
	v2.erase(remove_if(begin(v2), end(v2), even), end(v2));

	display_vector(v2);

	getchar();
	return 0;
}


