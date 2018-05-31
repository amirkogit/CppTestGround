//-----------------------------------------------------------------------------------------
// Demonstrates how to remove items from unsorted std::vector in O(1) time
// Reference: C++17 STL Cookbook
//
// Amir Shrestha [https://amirkoblog.wordpress.com/, @amirkotweet]
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
void display_vector(const vector<int> v)
{
    cout << "Content: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "size: " << v.size() << "\n\n";
}

template <typename T>
void quick_remove_at(std::vector<T>& v, std::size_t idx)
{
    if (idx < v.size()) {
        cout << "Removing item " << v[idx] << " with index " << idx << endl;
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T>& v, typename std::vector<T>::iterator it)
{
    if (it != std::end(v)) {
        cout << "Removing item " << *it << endl;
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main()
{
    cout << "Vector delete optimize demo" << endl;

    std::vector<int> v {502,412,112,87,698,55,20,15,114,35,78,8,21};
    display_vector(v);

    // remove item at index 2 which is 112. Here the order of items in the vector is not maintained
    quick_remove_at(v,2);
    display_vector(v);

    // normal remove. This will take O(n) time as the items have to be moved once 20 is removed
    cout << "Removing 20 ..." << endl;
    v.erase(remove(begin(v), end(v),20),end(v));
    display_vector(v);

    // remove item 114. The order of items in the vector is not maintained
    quick_remove_at(v, std::find(std::begin(v), std::end(v), 114));
    display_vector(v);

    // normal remove. This will take O(n) time
    cout << "Removing 21 ..." << endl;
    v.erase(std::find(std::begin(v), std::end(v), 21));
    display_vector(v);

    return 0;
}
#endif
