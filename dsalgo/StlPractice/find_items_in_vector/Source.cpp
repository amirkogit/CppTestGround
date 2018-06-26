// Reference: C++17 STL Cookbook
// Finding items in a vector that contains ordered and unorderd list
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct city {
	string name;
	unsigned population;
};

bool operator == (const city& lhs, const city& rhs)
{
	return  lhs.name == rhs.name && lhs.population == rhs.population;
}

ostream& operator << (ostream& os, const city& city)
{
	return os << "{" << city.name << ", " << city.population << "}";
}

template <typename C>
static auto opt_print(const C& container)
{
	return[end_it (end(container))](const auto& item) {
		if (item != end_it) {
			cout << *item << '\n';
		}
		else {
			cout << "<end>\n";
		}
	};
}

int main()
{
	const vector<city> cities{
		{"davie", 246000},
		{"palo alto", 265444},
		{"des moine", 3502000},
		{"new foundland", 106000}
	};

	auto print_city(opt_print(cities));

	// using find: method 1
	{
		auto found_des_moine(find(begin(cities), end(cities), city{ "des moine", 3502000 }));
		print_city(found_des_moine);
	}

	// using find_if: method 2
	{
		auto found_des_moine(find_if(begin(cities), end(cities),
			[](const auto& item) {return item.name == "des moine"; }));

		print_city(found_des_moine);
	}

	// using predicate builders
	{
		auto population_more_than([](unsigned i) {
			return [=](const city& item) {
				return item.population > i;
			};
		});

		auto found_large(find_if(begin(cities), end(cities), population_more_than(90200000)));
		print_city(found_large);
	}

	// using binary_search
	const vector<int> v{1,2,3,4,5,6,7,8,9,10};
	auto print_int(opt_print(v));

	bool contains_7 = binary_search(begin(v), end(v), 7);
	cout << "contains_7?: " << contains_7 << '\n';

	auto[lower_it, upper_it] = equal_range(begin(v), end(v), 7);
	cout << "equal_range: \n";
	print_int(lower_it);
	print_int(upper_it);

	cout << "lower_bound and upper_bound: \n";
	print_int(lower_bound(begin(v), end(v), 7));
	print_int(upper_bound(begin(v), end(v), 7));

	getchar();
	return 0;
}
