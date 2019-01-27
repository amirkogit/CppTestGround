#include <QCoreApplication>
#include <vector>
#include <iostream>

#include "utils.h"

using namespace std;

class array_of_ints {
public:
    array_of_ints();
    int size() const { return 10; }
    int& at(int i) { return data[i]; }

private:
    int data[10] = {};
};

// constructor
array_of_ints::array_of_ints()
{
    for(int i = 0; i < 10; ++i) {
        data[i] = i*2 + 1;
    }
}

void double_each_element(array_of_ints& arr)
{
    for(int i = 0; i < arr.size(); ++i) {
        arr.at(i) *= 2;
    }
}

void print_elements(array_of_ints& arr, const string& msg)
{
    cout << "Elements of arr are [" << msg << "]:" << "\n";

    for(int i = 0; i < arr.size(); ++i) {
        cout << arr.at(i) << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Test application\n";

    // Test utils.h function
    TestFunction();

    array_of_ints my_arr;
    print_elements(my_arr, "Before");
    double_each_element(my_arr);
    print_elements(my_arr, "After");

    return a.exec();
}
