#include <QCoreApplication>
#include <iostream>
#include <string>
#include <sstream>

namespace sample1 {

// one way of initializing using a global variable. Other way is to define a static within a class
//struct { int d,m,y; } date_initializer = {1,1,1970};

class Date {
public:
    explicit Date(int dd = 0, int mm = 0, int yy = 0);

    std::string get_date() const;

    Date& add_day(int day);
    Date& add_month(int month);
    Date& add_year(int year);

    int get_day() const;
    int get_month() const;
    int get_year() const;

private:
    void compute_cache() const;

private:
    int m_day {m_defaultDate.m_day};
    int m_month {m_defaultDate.m_month};
    int m_year {m_defaultDate.m_year};

    mutable bool m_cacheValid {false};
    mutable std::string m_cache;

    static Date m_defaultDate;
};

Date Date::m_defaultDate {1,1,1970};

Date::Date(int dd, int mm, int yy)
{
    m_day = dd ? dd : m_defaultDate.m_day;
    m_month = mm ? mm : m_defaultDate.m_month;
    m_year = yy ? yy : m_defaultDate.m_year;
}

std::string Date::get_date() const
{
    if(!m_cacheValid) {
        compute_cache();
        m_cacheValid = true;
    }

    return m_cache;
}

Date& Date::add_day(int day)
{
    m_day += day;
    m_cacheValid = false;
    return *this;
}

Date& Date::add_month(int month)
{
    m_month += month;
    m_cacheValid = false;
    return *this;
}

Date& Date::add_year(int year)
{
    m_year += year;
    m_cacheValid = false;
    return *this;
}

int Date::get_day() const
{
    return m_day;
}

int Date::get_month() const
{
    return m_month;
}

int Date::get_year() const
{
    return m_year;
}

void Date::compute_cache() const
{
    std::stringstream ss;
    ss << m_day << "/" << m_month << "/" << m_year;
    m_cache = ss.str();
}

void func(Date& d, const Date& cd)
{
    using namespace std;

    int y1 = d.get_year(); // ok
    d.add_year(2); // ok

    int y2 = cd.get_year(); // ok
    //cd.add_year(2); // error: cannot change value of const Date

    cout << d.get_date() << endl;
    cout << cd.get_date() << endl;
}

void f1(Date date)
{}

void f2(Date date)
{}

void f2(int n)
{}

void g()
{
//    f1({}); // error
    f1(Date{}); // ok
    f2(Date{}); // ok
    f2(24); // ok
//    f2("some text"); // error
}

void test_sample1()
{
    using namespace std;

    Date d1;
    cout << "d1 = " << d1.get_date() << endl;
    Date d2(8);
    cout << "d2 = " << d2.get_date() << endl;
    Date d3(8,12);
    cout << "d3 = " << d3.get_date() << endl;
    Date d4(8,12,2015);
    cout << "d4 = " << d4.get_date() << endl;

    d1.add_day(22);
    cout << "d1 = " << d1.get_date() << endl;
    d4.add_year(2);
    cout << "d4 = " << d4.get_date() << endl;

    cout << endl;
    cout << "d4 = " << d4.get_day() << ":" << d4.get_month() << ":" << d4.get_year() << endl;

    func(d1,d2);

    Date d5;
    cout << "d5 = " << d5.get_date() << endl;
    d5 = d5.add_day(2).add_month(3).add_year(5);
    cout << "After add d5 = " << d5.get_date() << endl;
}

} // end of namespace sample1



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sample1::test_sample1();

    return a.exec();
}
