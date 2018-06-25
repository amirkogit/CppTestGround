// Reference: C++17 STL Cookbook
// Sorting containers
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

using namespace std;

static void print(const vector<int>& v)
{
	copy(begin(v), end(v), ostream_iterator<int> {cout, ", "});
	cout << "\n";
	cout << "vector sorted? " << is_sorted(begin(v), end(v)) << "\n\n";
}

struct mystruct {
	int a;
	int b;
};

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	random_device rd;
	mt19937 g{ rd() };

	print(v);

	shuffle(begin(v), end(v), g);
	print(v);
	
	sort(begin(v), end(v));
	print(v);

	shuffle(begin(v), end(v), g);
	print(v);
	cout << "Partition with 5\n";
	partition(begin(v), end(v), [](int i) { return i < 5; });
	print(v);

	shuffle(begin(v), end(v), g);
	auto middle(next(begin(v), int(v.size()) / 2));
	partial_sort(begin(v), middle, end(v));
	print(v);

	// sorting a data structure that has no comparision operator
	vector<mystruct> mv{
		{5,100}, {1,50}, {-123,1000},
		{3,70}, {-10,20}
	};

	auto print_mv = [&]() {
		for (const auto&[a, b] : mv) {
			cout << "{" << a << ", " << b << "} ";
		}
		cout << "\n";
	};

	cout << "original list: ";
	print_mv();

	sort(begin(mv), end(mv), [](const mystruct& lhs, const mystruct& rhs) {
		return lhs.b < rhs.b;
	});

	cout << "after sort: ";
	print_mv();

	getchar();
	return 0;
}