#include <iostream>
#include <string>
#include <complex>
#include "FunctionTemplates.hpp"

using namespace std;

class MyClass {

};

// rename the function to main() to run this as a main program
int mainFunctionTemplates()
{
    cout << "Calling getmaxForSameType()\n";
    cout << getMaxForSameType(3,6) << endl; // returns 6
    cout << getMaxForSameType<int>(77,21) << endl; // returns 77
    cout << getMaxForSameType(3.6,8.25) << endl; // returns 8.25
    cout << getMaxForSameType<float>(77.87,21.689) << endl; // returns 77.87

    string s1 = "hello";
    string s2 = "world";

    cout << getMaxForSameType(s1,s2) << endl; // returns world

    MyClass c1,c2;
    // Following will not compile as we have not defined overload for operator <
    //cout << getMaxForSameType(c1,c2) << endl;

    std::complex<float> complex1;
    std::complex<float> complex2;
    
    // Following will not compile as operator < is not provided
    //cout << getMaxForSameType(complex1,complex2) << endl;

    cout << endl;
    cout << "For different types\n";

    cout << getMaxForDifferentTypes(4,5.6) << endl;         // returns 5
    cout << getMaxForDifferentTypes<double>(4,5.6) << endl; // returns 5.6
    cout << getMaxForDifferentTypes(4.0,5.6) << endl;       // returns 5.6
    cout << getMaxForDifferentTypes<int>(4,5.6) << endl;    // returns 5

    cout << endl;
    cout << "Testing overloaded template functions\n";
    cout << getMin(5,8) << endl;        // returns 5 (calls nontemplate version)
    cout << getMin<int>(15,9) << endl;  // returns 9 (calls template version by argument deduction)
    cout << getMin(8.6,3.56) << endl;   // returns 3.56 (calls template version)
    cout << getMin(20,32,4) << endl;    // return 4 (first calls template version)
                                        // and then calls normal version for two subsequent calls
    cout << getMin<int>(20,32,4) << endl; // same as for getMin(20,32,4)
    cout << getMin('a',100) << endl;    // returns 97 (ascii value for a) by calling non-template version
    cout << getMin(10,'a') << endl;     // returns 10 by calling non-template version

    int a = 100; int *pa = &a;
    int b = 200; int *pb = &b;
    cout << *getMin(pa,pb) << endl;     // returns 100 (calls pointer version of template function)

    getchar();
    return 0;
}