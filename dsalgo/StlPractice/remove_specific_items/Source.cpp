// Reference: C++17 STL Cookbook
// Remove specific items from the containers
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// helper function to print out the vector
void print(const vector<int>& v)
{
	copy(begin(v), end(v), ostream_iterator<int> {cout, " "});
	cout << '\n';
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	print(v);

	// remove all with the value 2
	{
		const auto new_end(remove(begin(v), end(v), 2));
		v.erase(new_end, end(v));
	}
	
	print(v);

	// remove all odd numbers
	{
		auto odd_number([](int i) { return i % 2 != 0; });
		const auto new_end(remove_if(begin(v), end(v), odd_number));
		v.erase(new_end, end(v));
	}

	print(v);

	// replace all 4 with 400
	replace(begin(v), end(v), 4, 400);
	print(v);

	// replace all even with square of its number
	{
		auto even_number ([](int i) { return i % 2 == 0; });
		replace_if(begin(v), end(v), even_number, 555);
		print(v);
	}

	// copy only even id numbers from the original list to two other
	// containers with two different methods.
	vector<int> ids{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> even_ids_1;
	vector<int> even_ids_2;

	auto check_odd_id([](int i) { return i % 2 != 0; });
	auto check_even_id([](int i) { return i % 2 == 0; });

	print(ids);

	// method 1: 
	copy_if(begin(ids), end(ids), back_inserter(even_ids_1), check_even_id);
	print(even_ids_1);

	// method 2:
	remove_copy_if(begin(ids), end(ids), back_inserter(even_ids_2), check_odd_id);
	print(even_ids_2);

	getchar();
	return 0;
}