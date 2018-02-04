//
// Created by Anton on 2/3/2018.
//

#ifndef LAB3_TOSTRING_H
#define LAB3_TOSTRING_H


#include <sstream>

template <typename T>
std::string toString(T const &value) {
    std::ostringstream oss;
    oss << value;
    std::string s = oss.str();
    return s;

}

#endif //LAB3_TOSTRING_H
