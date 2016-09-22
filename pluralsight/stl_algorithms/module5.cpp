/*
* Pluralsight : Beautiful STL Algorithms
*
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "stl_algo_demo.h"

// standard library header includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Resource
{
    int i = 1;
    static int objectcount;
public:
    Resource();
    Resource(const Resource& r);
    Resource& operator=(const Resource&r);
    ~Resource();
    void setValue(int ii) { i = ii; }
    int getvalue() const { return i; }
};

int Resource::objectcount = 0;

Resource::Resource()
{
    objectcount++;
}

Resource::Resource(const Resource & r)
{
    i = r.i;
    objectcount++;
}

Resource & Resource::operator=(const Resource & r)
{
    i = r.i;
    return *this;
}


Resource::~Resource()
{
    objectcount--;
}

void Generating()
{
    vector<int> source{ 3, 6, 1, 0, -2, 5 };
    vector<int> v2(source.size());

    copy(begin(source), end(source), begin(v2));

    auto v3 = source;

    auto position = find(begin(source), end(source), 1);
    vector<int> v4(source.size());
    copy(begin(source), position + 1, begin(v4));

    vector<int> v5(source.size());
    copy_if(begin(source), end(source), begin(v5),
        [](int elem) {return elem % 2 == 0; });

    copy_n(begin(v5), 3, begin(v2));

    copy(begin(source), position + 1, position + 1);

    copy_backward(begin(v3), end(v3), end(source));

    //copy(begin(source), end(source) - 1, begin(source) + 1);

    copy_backward(begin(source), end(source) - 1, end(source));

    auto newend = remove(begin(source), end(source), 3);
    int s = source.size();
    int logicalsize = newend - begin(source);
    source.erase(newend, end(source));

    source = v3;
    source.erase(remove(begin(source), end(source), 3), end(source));

    vector<Resource> vr(2);
    vr[0].setValue(8);
    vr[1].setValue(9);

    auto newend2 = remove_if(begin(vr), end(vr), [](const Resource& r) {return r.getvalue() == 8; });
    vr.erase(newend2, end(vr));

    vector<int> v6(10);
    fill(begin(v6), end(v6), 1);
    fill_n(begin(v6), 6, 2);
    iota(begin(v6), end(v6), 1);

    int index = 10;
    generate(begin(v6), end(v6), [&index]() {return --index; });
    source = v6;
    index = 1;
    generate_n(begin(v6), 7, [&index]() {return (index *= 2); });

    replace(begin(v6), end(v6), 2, 7);
    replace_if(begin(v6), end(v6), [](int elem) {return elem < 16; }, 7);

    transform(begin(source), end(source), begin(source), [](int elem) {return elem * 2; });
    transform(begin(source), end(source) - 1, begin(source) + 1, begin(v6), [](int elem1, int elem2) {return elem1 - elem2; });

    iota(begin(v6), end(v6), 1);
    iota(begin(source), end(source), 2);
    vector<int> v7(10);
    transform(begin(source), end(source), begin(v6), begin(v7), [](int elem1, int elem2) {return elem1 + elem2; });

    unique(begin(v2), end(v2));
    v2[3] = -2;
    auto v8 = v2;
    v2.erase(unique(begin(v2), end(v2)), end(v2));
    unique_copy(begin(v8), end(v8), begin(v7));

    string sentence = "Hello, world!";
    reverse(begin(sentence), end(sentence));

    iter_swap(begin(v7), end(v7) - 1);

    string orig = "             ";
    reverse_copy(begin(sentence), end(sentence), begin(orig));
}
void STLAlgorithms::RunModule5Demo()
{
    Generating();

}