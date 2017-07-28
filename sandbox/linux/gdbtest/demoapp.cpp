#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    cout << "gdb debugger demo..." << endl;

    int size  = 10;
    std::string name = "hello";

    vector<int> i_vec;
    i_vec.push_back(10);
    i_vec.push_back(20);
    i_vec.push_back(30);

    cout << "Size of a vector: " << i_vec.size() << endl;

    map<string,int> name_age_map = {{"Bob",30},{"Harry",45},{"Susan",26}};
    cout << "Size of a map: " << name_age_map.size() << endl;
    
    cout << "End of program" << endl;
}
