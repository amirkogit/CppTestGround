#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
class MyStack {
public:
    MyStack<T>() {}                                     // default constructor
    MyStack(const MyStack<T>& other);                   // copy constructor
    MyStack<T>& operator= (const MyStack<T>& other);    // assignment operator

    MyStack(MyStack<T>&& other) noexcept{               // move constructor
        m_items(std::move(other.m_items));
    }

    MyStack<T>& operator=(MyStack<T>&& other) {         // move assignment
        m_items = std::move(other.m_items);
        return *this;
    }

    void push(const T& item);

    void pop();

    T top() const;

    bool isEmpty() {
        return m_items.empty();
    }
private:
    std::vector<T> m_items;
};

template<typename T>
MyStack<T>::MyStack(const MyStack<T>& other)
{
    m_items = other.m_items;
}

template<typename T>
MyStack<T>& MyStack<T>::operator= (const MyStack<T>& other)
{
    m_items = other.m_items;
    return *this;
}

template<typename T>
void MyStack<T>::push(const T& item)
{
    m_items.push_back(item);
}

template<typename T>
void MyStack<T>::pop()
{
    if (m_items.empty()) {
        throw std::out_of_range("Invoked MyStack<>::pop -> Stack is empty.");
    }
    m_items.pop_back();
}

template<typename T>
T MyStack<T>::top() const
{
    if (m_items.empty()) {
        throw std::out_of_range("Invoked MyStack<>::top -> Stack is empty.");
    }
    return m_items.back();
}