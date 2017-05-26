#pragma once
#include<string>

using namespace std;

class MyClass final {
public:
    explicit MyClass(const int& id, const string& name)
        :m_classId(id), m_className(name)
    {
    }

    int getClassId() const { return m_classId; }
    string getClassName() const { return m_className; }

private:
    int m_classId;
    string m_className;
};
