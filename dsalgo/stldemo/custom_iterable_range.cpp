// Reference: C++17 STL Cookbook
// Implement an iterator that emits a range of numbers when iterating through it
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>

#if 0

using namespace std;

class num_iterator
{
public:
    explicit num_iterator(int position = 0) : m_iter {position} {}

    int operator*() const { return m_iter;}

    num_iterator& operator++() {
        ++m_iter;
        return *this;
    }

    bool operator != (const num_iterator& other) const {
        return  m_iter != other.m_iter;
    }

private:
    int m_iter;
};

class num_range
{
public:
    num_range(int first, int last): m_first {first}, m_last {last} { }

    num_iterator begin() const { return num_iterator {m_first}; }
    num_iterator end() const { return num_iterator {m_last}; }

private:
    int m_first;
    int m_last;
};

int main()
{
    for (int i : num_range {200,215}) {
            std::cout << i << ", ";
    }
    std::cout << "\n";

    return 0;
}
#endif
