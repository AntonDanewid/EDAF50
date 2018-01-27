#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <sstream>

using namespace std;

using std::string;
using std::vector;

Dictionary::Dictionary() {
    string filename = "F:\\Work\\School\\C++\\EDAF50\\Labs\\lab2\\computedWords.txt";
    ifstream input(filename);
    cout << "hello";


    if (!input) { // "if the file couldn’t be opened"
        std::cerr << "Could not open: " << filename << endl;
        exit(1);
    }


    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            if (line.size() > 0) {
                std::transform(line.begin(), line.end(), line.begin(), ::tolower);
                line.erase(remove(line.begin(), line.end(), '\n'), line.end());
                line.erase(remove(line.begin(), line.end(), '\r'), line.end());
                vector<string> result;
                std::string s = line;
                istringstream iss(s);
                for (string s; iss >> s;) {
                    result.push_back(s);
                }
                string word = result.at(0);
                vector<string> trigram;
                for (int i = 2; i < result.size(); ++i) {
                    trigram.push_back(result.at(i));
                }

                sort(trigram.begin(), trigram.end());
                Word w(word, trigram);
                if (word.size() <= 25) {
                words[word.size()-1].push_back(w);
            }

            }
        }
        input.close();
        cout << words[2].at(0).get_word();

    }


}

bool Dictionary::contains(const string &word) const {
    int index  = word.size()-1;
    if(index >= 25) {
        return false;
    }
    vector<Word> search = words[index];
    for(int i = 0; i < search.size(); i++) {
        if(search.at(i).get_word() == word) {
            return true;
        }
    }
    return false;
}

vector<string> Dictionary::get_suggestions(const string &word) const {
    vector<string> suggestions;
    add_trigram_suggestions(suggestions, word);

    rank_suggestions(suggestions, word);
    //trim_suggestions(suggestions);
    return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, string word) const{
    int size = word.size();
    vector<string> trigrams;
    string trigram ="";
    for (int i = 0; i < word.size() - 2; i++) {
        string trigram ="";
        char c[] = {word.at(i), word.at(i + 1), word.at(i + 2)};
        trigram += c[0];
        trigram += c[1];
        trigram += c[2];
        trigrams.push_back(trigram);
    }

    vector<Word> wordsU = words[size +1];
    vector<Word> wordsM = words[size];
    vector<Word> wordsD = words[size -1];
    for(Word w: wordsU) {
        if(w.get_matches(trigrams) >= size/2) {
            suggestions.push_back(w.get_word());
        }
    }

    for(Word w: wordsM) {
        if(w.get_matches(trigrams) >= size/2) {
            suggestions.push_back(w.get_word());
        }
    }

    for(Word w: wordsD) {
        if(w.get_matches(trigrams) >= size/2) {
            suggestions.push_back(w.get_word());
        }
    }



}

void Dictionary::rank_suggestions(std::vector<std::string> &suggestions, std::string word) const {
    int d[26][26];
    

}


