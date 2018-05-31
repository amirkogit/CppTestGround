//-----------------------------------------------------------------------------------------
// Demonstrates the usage of out of bound access of std::vector
// Reference: C++17 STL Cookbook
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

#if 0
int main()
{
    const size_t vec_size {2000};
    vector<double> v (vec_size, 50.87);

    // access vector using []
    cout << "Element at [200]: " << v[200] << endl;

    // this will crash the application
//    cout << "Element out of range access at [vec_size + 10]: " << v[vec_size + 10];

    // access vector using at()
    cout << "Element at [200] using at(): " << v.at(200) << endl;

    // this will crash the application
//    cout << "Element out of range access using at(): " << v.at(vec_size + 10) << endl;

    // catching out of range access. Benefit of using at() is that exception can be caught.
    // with access operator [] it is not possible to catch. Performance of at() is slower than []
    try {
        cout << "Element out of range access using at(): " << v.at(vec_size + 10) << endl;
    }
    catch(const std::out_of_range& e) {
        cout << "Out of range access: " << e.what() << endl;
    }

    return 0;
}
#endif
