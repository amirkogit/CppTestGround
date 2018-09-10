#pragma once

#include <iostream>

namespace CoreDS {
class SimpleList
{
public:
    SimpleList();
    ~SimpleList();

    int get(int index);
    void insert(int index, int val);
    int search(int val);
    void remove(int index);
    int getCount();
    void empty();
    void print();

private:
    int* m_data = nullptr;
    int m_count;
};
} // end namespace

