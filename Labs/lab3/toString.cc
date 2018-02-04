//
// Created by Anton on 2/3/2018.
//

//#include "toString.h"
#include <sstream>
#include <string>


template <typename T>
std::string toString(T const &value) {
    std::ostringstream oss;
    oss << value;
    std::string s = oss.str();
    return s;

}
