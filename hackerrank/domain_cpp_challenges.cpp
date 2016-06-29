/*
* Solutions to Hackerrank challenges
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

#include "hacker_rank_challenges.h"

// standard library header includes
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <cassert>
#include <sstream>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////
// Format for defining methods for each coding challenges
// Method name: Title of the problem statement
//              For example, if the problem statement title is "For Loop" in the subdomain Introduction,
//              method name will be IntroForLoop()
// To test call these methods from the method "RunAllDemos()"
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
void IntroHelloWorld()
{
    std::cout << "Hello World";
}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////

void IntroForLoop()
{
    // You will be given two positive integers, a and b (), separated by a newline.
    int a, b;
    cin >> a;
    cin >> b;

    map<int, string> digit_word_map;
    digit_word_map.insert(pair<int, string>(1, "one"));
    digit_word_map.insert(pair<int, string>(2, "two"));
    digit_word_map.insert(pair<int, string>(3, "three"));
    digit_word_map.insert(pair<int, string>(4, "four"));
    digit_word_map.insert(pair<int, string>(5, "five"));
    digit_word_map.insert(pair<int, string>(6, "six"));
    digit_word_map.insert(pair<int, string>(7, "seven"));
    digit_word_map.insert(pair<int, string>(8, "eight"));
    digit_word_map.insert(pair<int, string>(9, "nine"));

    for (int i = a; i <= b; i++) {
        // for all the integers in the range [a,b],print the english representation of it
        if (i >= 1 && i <= 9) {
            // print the english representation of it
            auto result = digit_word_map.find(i);
            string s = result->second;
            cout << s.c_str() << endl;
        }
        else {
            // if the number is even, print even otherwise print odd
            if (i % 2 == 0) {
                cout << "even\n";
            }
            else {
                cout << "odd\n";
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

// Introduction/Functions
// *****************************

//Add `int max_of_four(int a, int b, int c, int d)` here.
int max_of_four(int a, int b, int c, int d)
{
    vector<int> list = { a,b,c,d };
    auto max = std::max_element(list.begin(), list.end());
    return *max;
}

void IntroFunction()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    vector<int> list;
}

///////////////////////////////////////////////////////////

// Introduction/Pointer
void update(int *a, int *b) {
    // Complete this function    
    int tempa = *a;
    int tempb = *b;
    *a = tempa + tempb;
    *b = std::abs(tempa - tempb);
}

void IntroPointer()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}

///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Introduction/Arrays
void IntroArrays()
{
    int n; // size of array
    cin >> n;

    assert(!(n < 1 || n > 1000));

    vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    // reverse the vector contents
    std::reverse(arr.begin(), arr.end());

    // print the contents
    for (auto elem : arr) {
        cout << elem << " ";
    }
}

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Introduction/Preprocessor solution
// Sample solution
#define toStr(str) #str

#define io(data) cin >> data

#define foreach(arr, idx) \
for(int idx = 0; idx < arr.size(); idx++)

#define FUNCTION(name, op) \
void name(int &x, int y)\
{ \
    if(!(x op y)) \
        x = y;\
}

#define INF 1e9

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

void IntroPreprocessor()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }

    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
}
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Intro Operator overloading

class Matrix {
public:
    Matrix operator +(const Matrix& mat);
    vector<vector<int>> a;
};

Matrix Matrix::operator+(const Matrix& mat)
{
    Matrix temp_mat;
    int row = a.size();
    int col = a[0].size();

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        for (int j = 0; j < col; j++) {
            int sum = mat.a[i][j] + a[i][j];
            temp.push_back(sum);
        }
        temp_mat.a.push_back(temp);
    }
    return temp_mat;
}

void IntroOperatorOverloading()
{
    int cases, k;
    cin >> cases;
    for (k = 0; k<cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i<n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j<m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i<n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j<m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i<n; i++) {
            for (j = 0; j<m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Intro/variable sized arrays
///////////////////////////////////////////////////////////
void IntroVariableSizedArrays()
{
    // read N integer sequences value
    int total_sequence = 0;
    cin >> total_sequence;

    // read Q queries value
    int total_queries = 0;
    cin >> total_queries;

    vector<vector<int>> sequence_list;
    vector<pair<int, int>> query_list; // (index of sequence, index of element) pairs --> using vector instead of map

    // read all numbers for all sequences
    for (int seq_id = 0; seq_id < total_sequence; seq_id++) {
        vector<int> ith_seq;
        int seq_size = 0;
        cin >> seq_size;
        int num;
        for (int i = 0; i < seq_size; i++) {
            cin >> num;
            ith_seq.push_back(num);
        }

        sequence_list.push_back(ith_seq);
    }

    // read all queries
    for (int query_id = 0; query_id < total_queries; query_id++) {
        int seq_idx = 0;
        cin >> seq_idx;
        int elem_idx = 0;
        cin >> elem_idx;
        query_list.push_back(std::pair<int, int>(seq_idx, elem_idx));
    }

    // perform operations for each queries in the query list
#if 0 // print the contents of query_list
    for (auto elem : query_list) {
        cout << "First: " << elem.first << " " << "Second: " << elem.second << endl;
    }
#endif // 0

    for (auto elem : query_list) {
        // get the sequence
        int seq_id = elem.first;
        int elem_id = elem.second;

        assert(!(seq_id < 0 || seq_id > sequence_list.size()));

        cout << sequence_list.at(seq_id).at(elem_id) << endl;
    }

}
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Introduction/Overload operators
class Complex
{
public:
    int a, b;
    void input(string s)
    {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+')
        {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            i++;
        }
        int v2 = 0;
        while (i<s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator +(const Complex& lhs, const Complex& rhs)
{
    Complex result;
    result.a = lhs.a + rhs.a;
    result.b = lhs.b + rhs.b;
    return result;
}

ostream& operator <<(ostream& out_stream, Complex c)
{
    out_stream << c.a << "+i" << c.b;
    return out_stream;
}

void IntroOverloadOperator()
{
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Introduction/ Virtual functions

// global static variables
static int id_prof;
static int id_student;

// base class
class Person {
public:
    virtual void getdata() {
        cin >> _name;
        cin >> _age;
    }

    virtual void putdata() {
        cout << _name << " " << _age << " ";
    }
private:
    string _name;
    int _age;
};

// derived class
class Professor : public Person {
public:
    Professor() {
        id_prof++;
    }

    void getdata() override {
        Person::getdata();
        cin >> _publication;
        _cur_id = id_prof;
    }

    void putdata() override {
        Person::putdata();
        cout << _publication << " " << _cur_id << endl;
    }

private:
    int _publication;
    int _cur_id;
};

// derived class
class Student : public Person {
public:
    Student() {
        id_student++;
    }

    void getdata() override {
        Person::getdata();
        for (int i = 0; i < 6; ++i) {
            int mark;
            cin >> mark;
            _marks.push_back(mark);
        }
        _cur_id = id_student;
    }

    void putdata() override {
        Person::putdata();
        int sum = 0;
        for (auto elem : _marks) {
            sum += elem;
        }
        cout << sum << " " << _cur_id << endl;
    }

private:
    vector<int> _marks;
    int _cur_id;
};

void IntroVirtualFunctions()
{
    int n, val;
    cin >> n; // the number of objects that is going to be created
    constexpr int N = 4;
    //Person *per[n]; // this is giving compile error!! use C++14 compiler
    Person *per[N]; // this is giving compile error!! use C++14 compiler

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            per[i] = new Professor;
        }
        else {
            per[i] = new Student;
        }

        per[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        per[i]->putdata();
    }
}
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Strings/Strings
void StringsStrings()
{
    // read two strings
    string string1, string2;
    cin >> string1 >> string2;

    // print the length of these strings
    cout << string1.length() << " " << string2.length() << endl;

    // print the concatenation of these string
    cout << string1 + string2 << endl;

    // swap the first character of each string
    swap(string1[0], string2[0]);

    cout << string1 << " " << string2 << endl;
}
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Strings/ StringStream

vector<int> parseInts(string str) {
    // Complete this function
    stringstream ss(str);
    vector<int> result;

    while (!ss.eof()) {
        int n;
        ss >> n;
        result.push_back(n);
        char comma;
        ss >> comma;
    }

    return result;
}

void StringsStream()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
}
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Main function for calling other sub functions
// Uncomment the method name that you want to test
void HackerRankChallenges::RunDomainCppChallenges()
{
    std::cout << "Running all C++ domain challenges." << endl;

    //IntroHelloWorld();

    //IntroForLoop();

    //IntroFunction();

    //IntroPointer();

    //IntroArrays();

    //IntroPreprocessor();

    //IntroOperatorOverloading();

    //IntroVariableSizedArrays();

    //IntroOverloadOperator();

    //StringsStrings();

    StringsStream();
}



