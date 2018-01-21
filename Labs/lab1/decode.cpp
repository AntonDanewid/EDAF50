//
// Created by Anton on 1/20/2018.
//

#include "coding.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string filename;
    cout << "enter filename";
    cin >> filename;


    ifstream input(filename);


    if (!input) { // "if the file couldn’t be opened"
        std::cerr << "Could not open: " << filename << endl;
        exit(1);
    }
    string output;
    string line;
    if (input.is_open())
    {
        while ( getline (input,line) )
        {
            for(char& c : line) {
                output+=decode(c);
            }
        }
        input.close();
    }

    ofstream myfile;
    myfile.open (filename + ".dec");
    myfile << output;
    myfile.close();





}