#pragma once
#include <iostream>

// basic example of function template definition
// returns the maximum of the two supplied parameters (both of same type)
template <typename T>
inline const T& getMaxForSameType(const T& a, const T& b)
{
    return (a > b) ? a : b; 
}

// can specify different types
// return type is the deduced from the first type argument that is passed
template<typename T1, typename T2>
inline const T1& getMaxForDifferentTypes(const T1& a, const T2& b)
{
    return a < b ? b : a;
}

// examples of function overloading

// get the minimum of two int values
inline const int& getMin(const int& a, const int& b)
{
    std::cout << "Called non-template version\n";
    return a > b ? b : a;
}

// returns the minimum of two values of any type
template<typename T>
inline const T& getMin(const T& a, const T& b)
{
    std::cout << "Called template version\n";
    return a > b ? b : a;
}

// returns the minimum of three values of any type
template <typename T>
inline const T& getMin(const T& a, const T& b, const T& c)
{
    std::cout << "Called template version\n";
    return getMin(getMin(a,b),c);
}

// returns the minimum of two values for pointer types
template<typename T>
inline T* getMin(T* a, T* b)
{
    std::cout << "Called template version\n";
    return *a > *b ? b : a;
}