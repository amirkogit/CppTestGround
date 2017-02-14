#define BOOST_CB_DISABLE_DEBUG // The Debug Support has to be disabled, otherwise the code produces a runtime error.

#include <iostream>
#include <boost/array.hpp>
#include <boost/circular_buffer.hpp>
#include <assert.h>
#include <vector>

using namespace std;

void DemoBoostArray()
{
    cout << "Boost array demo" << endl;
    boost::array<int, 4> arr = {{1, 2, 3, 4}};
    cout << "array contents: " << arr[0] << endl;
}

void DemoCircularBuffer()
{
    cout << "Boost circular buffer demo:" << endl;

    // create a circular buffer with a capacity of 3 integers
    boost::circular_buffer<int> cb(3);

    // insert some elements into the buffer
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);

    int a = cb[0];
    int b = cb[1];
    int c = cb[2];

    cb.push_back(4);
    cb.push_back(5);

    a = cb[0];
    b = cb[1];
    c = cb[2];

    cout << "contents of circular buffer: " << a << " " << b << " " << c << endl;
}

void DemoCircularBufferIteratorInvalidation()
{
    boost::circular_buffer<int> cb(3);

    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);

    boost::circular_buffer<int>::iterator it = cb.begin();

    assert(*it == 1);

    cb.push_back(4);

    assert(*it == 4); // The iterator still points to the initialized memory.
}

int main()
{
    DemoBoostArray();

    DemoCircularBuffer();

    //DemoCircularBufferIteratorInvalidation();
    
    return 0;
}
