//
// Created by Anton on 2/4/2018.
//
#include "string_cast.h"
#include "date.h"
#include <string>
#include <iostream>

int main() {
    int i = 0;
    double d = 0;
    Date date;
    try {
        i = string_cast<int>("123");
        d = string_cast<double>("12.34");
        date = string_cast<Date>("2015-01-10");
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    try {
        date = string_cast<Date>("2015-4301-10");

    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }




    int res = i + i;
    cout << res << endl;
    cout << d << endl;
    cout << date;
}