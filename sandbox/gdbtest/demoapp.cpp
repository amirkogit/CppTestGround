#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "gdb debugger demo..." << endl;

    vector<int> i_vec;
    i_vec.push_back(10);
    i_vec.push_back(20);
    i_vec.push_back(30);

    cout << "Size of a vector: " << i_vec.size() << endl;

    cout << "End of program" << endl;

}
