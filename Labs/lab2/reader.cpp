//
// Created by Anton on 1/25/2018.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;



int main() {

    string filename ="words";



    ifstream input(filename);


    if (!input) { // "if the file couldn’t be opened"
        std::cerr << "Could not open: " << filename << endl;
        exit(1);
    }
    string output;
    string line;

    if (input.is_open()) {

        while (getline(input, line)) {
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());


            if (line.size() >= 3) {
                output += line + " " + to_string(line.size() - 2);

                for (int i = 0; i < line.size() - 2; i++) {
                    char c[] = {line.at(i), line.at(i + 1), line.at(i + 2)};
                    output += " ";
                    output += c[0];
                    output += c[1];
                    output += c[2];
                }


            }
            output += '\n';
        }
        input.close();

    }
    cout << "here";
    ofstream myfile;
    myfile.open ("computedWords.txt");
    myfile << output;
    myfile.close();


}