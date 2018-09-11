#include "list.h"

namespace CoreDS {
SimpleList::SimpleList() : m_count(0)
{

}

SimpleList::~SimpleList()
{

}

// get the item for the given index
int SimpleList::get(int index) const
{
    if(index < 0 || index > m_count) {
        return -1;
    }

    return m_data[index];
}

// Inserts the value in the given index
void SimpleList::insert(int index, int val)
{
    if(index < 0 || index > m_count) {
        return;
    }

    // copy the current array
    int* oldArray = m_data;

    m_count++;

    m_data = new int[m_count];

    for(int i = 0, j = 0; i < m_count; ++i) {
        if(index == i) {
            m_data[i] = val;
        }
        else {
            m_data[i] = oldArray[j];
            ++j;
        }
    }

    delete[] oldArray;
}

// Iterates each items in the list and returns the index for the matched value
int SimpleList::search(int val) const
{
    for(int i = 0; i < m_count; ++i) {
        if(m_data[i] == val) {
            return i;
        }
    }

    return -1;
}

// Removes the item for the given index
void SimpleList::remove(int index)
{
    if(index < 0 || index > m_count) {
        return;
    }

    int* oldArray = m_data;

    m_count--;

    m_data = new int[m_count];

    for(int i = 0, j = 0; i < m_count; ++i, ++j) {
        if(index == j) {
            ++j;
        }

        m_data[i] = oldArray[j];
    }

    delete[] oldArray;

}

// Returns the count of elements in the list
int SimpleList::getCount() const
{
    return m_count;
}

// Removes all items from the list
void SimpleList::empty()
{
    int totalElements = m_count;
    for(int i = totalElements - 1; i >= 0; --i) {
        remove(i);
    }
}

// Prints each items present in the list
void SimpleList::print() const
{
    using namespace std;
    for(int i = 0; i < m_count; ++i) {
        cout << m_data[i] << " ";
    }
    cout << endl;
}

}
