//
// Created by Anton on 2/4/2018.
//

#ifndef LAB3_STRING_CAST_H
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
T string_cast(string s) {
    T obj;
    istringstream ss(s);
    ss >> obj;
    if((ss.rdstate() & ios::failbit ) != 0) {
        throw std::invalid_argument("Invalid syntax.");

    }
    return obj;
}

#endif //LAB3_STRING_CAST_H
