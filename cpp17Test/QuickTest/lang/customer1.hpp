#include <string>
#include <utility>

class Customer {
public:
    Customer (std::string f, std::string l, long v) 
    : first(f), last(l), val(v) {

    }

    std::string getFirst() const {
        return first;
    }

    std::string getLast() const {
        return last;
    }

    long getValue() const {
        return val;
    }

private:
    std::string first;
    std::string last;
    long val;
};