#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
using namespace std;

using std::string;
using std::vector;

Dictionary::Dictionary() {
	string filename ="words.txt";
	ifstream input(filename);
	if (!input) { // "if the file couldn’t be opened"
		std::cerr << "Could not open: " << filename << endl;
		exit(1);
	}
	string line;
	if (input.is_open()) {
        while (getline(input, line)) {
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
			line.erase(remove(line.begin(), line.end(), '\n'), line.end());
			line.erase(remove(line.begin(), line.end(), '\r'), line.end());
			stringSet.insert(line);
		}
		input.close();

	}




}

bool Dictionary::contains(const string& word) const {
    auto search = stringSet.find(word);
    if(search != stringSet.end()) {
        return true;
    }
    return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
