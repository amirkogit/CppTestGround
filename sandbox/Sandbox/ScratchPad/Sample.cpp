#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>

using namespace std;


struct Door {
    int height() const {return 50;}
};

int main()
{
    cout << "test\n";
    std::vector<Door> doors;
    std::vector<int> heights;

    doors.push_back(Door());
    doors.push_back(Door());

    std::transform(doors.cbegin(),doors.cend(),
                   //heights.begin(), // ?? this will be an error if heights has not been initialized!
                   std::back_inserter(heights),
                   std::mem_fn(&Door::height));

    list<int> coll = {6,5,4,3,2,1,1,2,3,4,5,6};
    copy(coll.cbegin(),coll.cend(),
        ostream_iterator<int>(cout," "));

    remove(coll.begin(),coll.end(),3); // remove all elements with value 3

    cout << "\n";

    copy(coll.cbegin(),coll.cend(), // source
        ostream_iterator<int>(cout," ")); // destination

    getchar();
}