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
    input >> std::noskipws;
    istream_iterator<char> begin(input), end;
    std::string html(begin, end);


    regex tags("<[^<]*>");
    string output;

    regex_replace(back_inserter(output), html.begin(), html.end(), tags, "");
    ofstream myfile;


    std::size_t f = output.find("&gt;");
    output.replace(f, std::string("&gt;").length(), ">");



    f = output.find("&lt;");
    output.replace(f, std::string("&lt;").length(), "<");

    f = output.find("&nbsp;");
    output.replace(f, std::string("&nbsp;").length(), " ");

    f = output.find("&amp;");
    output.replace(f, std::string("&amp;").length(), "&");

/*

    output.replace(f, std::string("&gt").length(), ">");
    output.replace(f, std::string("&lt").length(), "<");
    output.replace(f, std::string("&gt").length(), ">");
    output.replace(f, std::string("&amp").length(), "&");

*/



    cout << output;


    myfile.open ("strippedHtml.txt");
    myfile << output;
    myfile.close();






}