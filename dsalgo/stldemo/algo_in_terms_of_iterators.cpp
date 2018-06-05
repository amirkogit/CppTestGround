// Reference: C++17 STL Cookbook
// Implementing algorithms in terms of iterators
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

#if 1

// fibonacci iterator class
class fibo_iter
{
public:
    fibo_iter() = default;
    explicit fibo_iter(size_t i) : m_i{i} {}

    // emit fibonacci number of the current step
    size_t operator*() const { return m_b; }

    // move to next fibonacci number
    fibo_iter& operator++() {
        const size_t old_b {m_b};
        m_b += m_a;
        m_a = old_b;
        ++m_i;
        return *this;
    }

    bool operator!=(const fibo_iter& other) const {
        return m_i != other.m_i;
    }

private:
    size_t m_i {0};
    size_t m_a {0};
    size_t m_b {1};
};

// fibonacci range class
class fibo_range
{
public:
    fibo_range(size_t end) : m_end {end} {}

    fibo_iter begin() const { return fibo_iter{}; }
    fibo_iter end() const { return fibo_iter{m_end}; }

private:
    size_t m_end;
};

int main()
{
    cout << "Fibonnacci series using iterators and range...\n";

    for(size_t i : fibo_range(10)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
#endif
