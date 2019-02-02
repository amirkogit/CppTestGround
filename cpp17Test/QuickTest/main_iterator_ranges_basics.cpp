#include <QCoreApplication>
#include <iostream>
#include <iterator>

// put in a different namespace 'iter_ranges' to avoid name clashes
namespace iter_ranges {
struct list_node {
    int data;
    list_node* next;
};

template<bool Const>
class list_of_ints_iterator {
    friend class list_of_ints;
    friend class list_of_ints_iterator<!Const>;

    using node_pointer = std::conditional_t<Const, const list_node*, list_node*>;
    node_pointer m_ptr;

    explicit list_of_ints_iterator(node_pointer p) : m_ptr(p) { }

public:
    // member typedefs required by std::iterator_traits
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = std::conditional_t<Const, const int*, int*>;
    using reference = std::conditional_t<Const, const int&, int&>;
    using iterator_category = std::forward_iterator_tag;

    reference operator*() const { return m_ptr->data; }

    auto& operator++() {
        m_ptr = m_ptr->next;
        return *this;
    }

    auto operator++(int) {
        auto result = *this;
        ++*this;
        return result;
    }

    // support comparision between iterator and const_iterator types
    template<bool R>
    bool operator==(const list_of_ints_iterator<R>& rhs) const {
        return m_ptr == rhs.m_ptr;
    }

    template<bool R>
    bool operator!=(const list_of_ints_iterator<R>& rhs) const {
        return m_ptr != rhs.m_ptr;
    }

    // support implicit conversion of iterator to const_iterator but not vice versa
    operator list_of_ints_iterator<true>() const {
        return list_of_ints_iterator<true> {m_ptr};
    }

};


class list_of_ints {
public:
    using const_iterator = list_of_ints_iterator<true>;
    using iterator = list_of_ints_iterator<false>;

    // begin and end member functions
    iterator begin() {
        return iterator {m_head};
    }

    iterator end() {
        return iterator {nullptr};
    }

    const_iterator begin() const {
        return const_iterator {m_head};
    }

    const_iterator end() const {
        return const_iterator {nullptr};
    }

    // other operations
    int size() const {
        return m_size;
    }

    void push_back(int value) {
        list_node* new_tail = new list_node {value, nullptr};
        if (m_tail) {
            m_tail->next = new_tail;
        }
        else {
            m_head = new_tail;
        }
        m_tail = new_tail;
        m_size += 1;
    }

    // destructor
    ~list_of_ints() {
        for (list_node* next, *p = m_head; p != nullptr; p = next) {
            next = p->next;
            delete p;
        }
    }

private:
    list_node* m_head = nullptr;
    list_node* m_tail = nullptr;
    int m_size = 0;
};


template<typename Iterator>
auto distance(Iterator begin, Iterator end)
{
    using Traits = std::iterator_traits<Iterator>;

    if constexpr (std::is_base_of_v<std::random_access_iterator_tag, typename Traits::iterator_category>) {
        return (end - begin);
    }
    else {
        auto result = typename Traits::difference_type {};
        for(auto it = begin; it != end; ++it) {
            ++result;
        }
        return result;
    }
}

template<typename Iterator, typename Predicate>
auto count_if(Iterator begin, Iterator end, Predicate pred)
{
    using Traits = std::iterator_traits<Iterator>;

    auto sum = typename Traits::difference_type{};

    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            ++sum;
        }
    }
    return sum;
}
} // end of namespace iter_ranges

void run_test()
{
    using namespace iter_ranges;
    list_of_ints lst;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(90);

    int dist = iter_ranges::distance(lst.begin(), lst.end());
    assert(dist == 3);
    std::cout << "distance = " << dist << "\n";

    int count = iter_ranges::count_if(lst.begin(), lst.end(), [](int i) { return i >3; });
    assert(count == 2);
    std::cout << "count = " << count << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Iterator and Ranges demo\n";
    run_test();

    return a.exec();
}
