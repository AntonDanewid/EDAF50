//
// Created by endor on 2018-01-24.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {


    string filename = "words";
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



            }
        }
        input.close();
    }





}