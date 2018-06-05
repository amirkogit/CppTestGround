// Reference: C++17 STL Cookbook
// Implement custom iterators that is compatible with STL iterator categories
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>

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

    bool operator == (const num_iterator& other) const {
        return !(*this != other);
    }

private:
    int m_iter;
};

// My GCC compiler didn't need this code!
namespace std {
template<>
struct iterator_traits<num_iterator> {
  using iterator_category = std::forward_iterator_tag;
  using value_type = int;
};
}

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

#if 0
int main()
{
    num_range range {200, 210};
    auto [min_it, max_it] (std::minmax_element(std::begin(range), std::end(range)));
    std::cout << *min_it << " " << *max_it << '\n';

    return 0;
}
#endif
