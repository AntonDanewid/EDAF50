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
	unsigned int inCounter = 0;
    unsigned int outCounter = 0;
    while(outCounter < t.size() && inCounter < trigrams.size()) {
        if(t.at(outCounter) == trigrams.at(inCounter)) {
            inCounter ++;
            outCounter++;
            counter++;
        } else if(trigrams.at(inCounter) < t.at(outCounter)) {
            inCounter++;
        } else {
            outCounter++;
        }
    }




	return counter;
}
