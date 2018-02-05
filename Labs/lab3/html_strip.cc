//
// Created by Anton on 2/3/2018.
//

#include <regex>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>






using namespace std;


int main() {


    ifstream input("test.html");

    istream_iterator<char> begin(input), end;
    vector<char> html(begin, end);
    for(char c: html) {
        cout << c;
    }

    regex tags("<[^<]*>?&[^<]*;");
    string output;

    regex_replace(back_inserter(output), html.begin(), html.end(), tags, "");
    ofstream myfile;



    cout << output;


    myfile.open ("strippedHtml.txt");
    myfile << output;
    myfile.close();






}