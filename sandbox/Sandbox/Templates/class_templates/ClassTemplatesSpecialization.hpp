#pragma once

#include <vector>
#include <stdexcept>
#include <deque>
#include <string>

// Default stack class that will be used later for specialization
// This is same as MyStack class. Created a new class here to
// demonstrate clearly how the specialization of template class works
template<typename T>
class MyStackSpecialization {
public:
    MyStackSpecialization<T>() {}                                                   // default constructor
    MyStackSpecialization(const MyStackSpecialization<T>& other);                   // copy constructor
    MyStackSpecialization<T>& operator= (const MyStackSpecialization<T>& other);    // assignment operator

    MyStackSpecialization(MyStackSpecialization<T>&& other) noexcept {              // move constructor
        m_items(std::move(other.m_items));
    }

    MyStackSpecialization<T>& operator=(MyStackSpecialization<T>&& other) {         // move assignment
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


// Specialization of Class Templates for string type
// Uses std::deque instead of std::vector as container
// Here as the class template is specialized, so we need to specialize all member functions
// NOTE: The definition of specialize class must come before any definitions for default
// class template. For eg,push(), pop(), top(), copy constructor and copy assignment definitions
// comes later after this class
template<>
class MyStackSpecialization<std::string> {
public:
    MyStackSpecialization() {}

    MyStackSpecialization(const MyStackSpecialization<std::string>& other)
    {
        m_items = other.m_items;
    }

    MyStackSpecialization<std::string>& operator= (const MyStackSpecialization<std::string>& other)
    {
        m_items = other.m_items;
        return *this;
    }

    // move constructor is provided otherwise falls back to the default template class
    MyStackSpecialization(MyStackSpecialization<std::string>&& other) noexcept {               
        m_items = std::move(other.m_items);
    }

    // move assignment is provided here, otherwise falls back to the default template class
    MyStackSpecialization<std::string>& operator=(MyStackSpecialization<std::string>&& other) {
        m_items = std::move(other.m_items);
        return *this;
    }

    void push(const std::string& item) {
        m_items.push_back(item);
    }

    void pop() {
        if (m_items.empty()) {
            throw std::out_of_range("Invoked MyStack<>::pop -> Stack is empty.");
        }
        m_items.pop_back();
    }

    std::string top() const {
        if (m_items.empty()) {
            throw std::out_of_range("Invoked MyStack<>::top -> Stack is empty.");
        }
        return m_items.back();
    }

    bool isEmpty() const {
        return m_items.empty();
    }
private:
    std::deque<std::string> m_items;
};


// Following function definitions should come after MyStackSpecialization<std::string> 
// has been fully defined as above

template<typename T>
MyStackSpecialization<T>::MyStackSpecialization(const MyStackSpecialization<T>& other)
{
    m_items = other.m_items;
}

template<typename T>
MyStackSpecialization<T>& MyStackSpecialization<T>::operator= (const MyStackSpecialization<T>& other)
{
    m_items = other.m_items;
    return *this;
}

template<typename T>
void MyStackSpecialization<T>::push(const T& item)
{
    m_items.push_back(item);
}

template<typename T>
void MyStackSpecialization<T>::pop()
{
    if (m_items.empty()) {
        throw std::out_of_range("Invoked MyStack<>::pop -> Stack is empty.");
    }
    m_items.pop_back();
}

template<typename T>
T MyStackSpecialization<T>::top() const
{
    if (m_items.empty()) {
        throw std::out_of_range("Invoked MyStack<>::top -> Stack is empty.");
    }
    return m_items.back();
}
