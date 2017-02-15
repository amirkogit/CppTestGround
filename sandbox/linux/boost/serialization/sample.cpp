// code adapted from Boost/Serialization tutorial

#include <iostream>
#include <fstream>

// include headers that implement a archive in a simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

using namespace std;

class GPSPosition
{
public:
    GPSPosition() {};

    GPSPosition(int deg, int min, float sec)
    : _degrees(deg), _minutes(min), _seconds(sec)
    {
    }


private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & _degrees;
        ar & _minutes;
        ar & _seconds;
    }

    friend std::ostream & operator <<(std::ostream &os, const GPSPosition &pos)
    {
        return os << ' ' << pos._degrees << " deg" << pos._minutes << '\'' << pos._seconds << '"';
    }

private:
    int _degrees;
    int _minutes;
    float _seconds;
};

int main()
{
    cout << "Boost Serialization demo" << endl;

    std::ofstream ofs("arfile");

    const GPSPosition pos(44, 60, 33.56f);

    // save data to archive
    {
        boost::archive::text_oarchive oa(ofs);
        oa << pos;
    }

    GPSPosition new_pos;
    {
        std::ifstream ifs("arfile");
        boost::archive::text_iarchive ia(ifs);
        ia >> new_pos;
    }

    //cout << "Newpos value: " << new_pos._degrees << endl;
    cout << "Newpos value: " << new_pos << endl;


    return 0;
}