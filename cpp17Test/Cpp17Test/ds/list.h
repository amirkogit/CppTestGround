#pragma once

#include <iostream>

namespace CoreDS {
class SimpleList final
{
public:
    SimpleList();
    ~SimpleList();

    int get(int index) const;
    void insert(int index, int val);
    int search(int val) const;
    void remove(int index);
    int getCount() const;
    void empty();
    void print() const;

private:
    int* m_data = nullptr;
    int m_count;
};
} // end namespace

