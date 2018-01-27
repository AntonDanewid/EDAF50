#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <regex>

using namespace std;

using std::string;
using std::vector;

Dictionary::Dictionary() {
    string filename = "words.txt";
    ifstream input(filename);
    if (!input) { // "if the file couldn’t be opened"
        std::cerr << "Could not open: " << filename << endl;
        exit(1);
    }

    std::string s = "split on    whitespace   ";

    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            line.erase(remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(remove(line.begin(), line.end(), '\r'), line.end());
            vector<string> result;
            istringstream iss(s);
            for (string s; iss >> s;) {
                result.push_back(s);
            }
            string word = result.at(0);
            vector<string> trigram;
            for(int i =2; i < result.size(); ++i) {
                trigram.push_back(result.at(i));
            }

            sort(trigram.begin(), trigram.end());
            cout << trigram.at(0);
            Word w(word, trigram);
            words[word.size()].push_back(w);

        }
        input.close();

    }



}

bool Dictionary::contains(const string &word) const {
    auto search = stringSet.find(word);
    if (search != stringSet.end()) {
        return true;
    }
    return false;
}

vector<string> Dictionary::get_suggestions(const string &word) const {
    vector<string> suggestions;
    return suggestions;
}

