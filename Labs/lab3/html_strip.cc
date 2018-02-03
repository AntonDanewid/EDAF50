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
    regex tags("<[^<]*>", "<*> &*;");
    string result;
    regex_replace(back_inserter(result), html.begin(), html.end(), tags, " ");






    ofstream myfile;
    myfile.open ("strippedHtml.txt");
    myfile << result;
    myfile.close();


}