// Reference: C++17 STL Cookbook
// String Pattern matching 
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

template <typename Itr>
static void print(Itr it, size_t chars)
{
	copy_n(it, chars, ostream_iterator<char>{cout});
	cout << '\n';
}

int main()
{
	const string msg {"If execution of a function invoked as part of the algorithm throws an exception and ExecutionPolicy is one of the three standard policies, std::terminate is called. For any other ExecutionPolicy, the behavior is implementation-defined."};
	const string match_str{ "algorithm" };

	{
		auto match(search(begin(msg), end(msg), begin(match_str), end(match_str)));
		print(match, 8);
	}

	{
		auto match(search(
			begin(msg), end(msg), 
			default_searcher(begin(match_str), end(match_str))));
		print(match, 8);
	}

	{
		auto match(search(begin(msg), end(msg),
			boyer_moore_searcher(begin(match_str), end(match_str))));
		print(match, 8);
	}

	{
		auto match(search(begin(msg), end(msg),
			boyer_moore_horspool_searcher(begin(match_str), end(match_str))));
		print(match, 8);
	}

	getchar();
	return 0;
}