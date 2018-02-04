//
// Created by Anton on 2/3/2018.
//

#include "date.h"
#include <iostream>
#include "toString.h"



using namespace std;
int main() {



    Date d(2014,5,2);
    double a = 2.213;
    string s = "hey";
    string date = toString(d);
    cout << date << endl;
    string nbr = toString(a);
    cout << nbr << endl;


}
