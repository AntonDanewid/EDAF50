#include <string>
#include <vector>
#include <algorithm>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t){}


string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int counter = 0;
	for(std::string s: trigrams) {
		if(std::find(t.begin(), t.end(), s) != t.end()) {
			counter++;
		}
	}
	return counter;
}
