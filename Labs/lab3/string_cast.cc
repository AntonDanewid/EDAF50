//
// Created by Anton on 2/4/2018.
//

#include <string>
//#include "string_cast.h"
using namespace std;

template <typename T>
T string_cast(string s) {
    T obj;
    s >> obj;
}