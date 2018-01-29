#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using namespace std;

using std::string;
using std::vector;

Dictionary::Dictionary() {
    string filename = "computedWords.txt";
    ifstream input(filename);


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
                for (unsigned int i = 2; i < result.size(); ++i) {
                    trigram.push_back(result.at(i));
                }

                sort(trigram.begin(), trigram.end());
                Word w(word, trigram);
                stringSet.insert(word);
                if (word.size() <= 25) {
                words[word.size()-1].push_back(w);
            }

            }
        }
        input.close();

    }


}

bool Dictionary::contains(const string &word) const {
    int index  = word.size()-1;

    if(index >= 25) {
        return false;
    }

    if(stringSet.find(word) != stringSet.end()) {
        return true;

    }
    return false;
}

vector<string> Dictionary::get_suggestions(const string &word) const {
    vector<string> suggestions;

    add_trigram_suggestions(suggestions, word);

    rank_suggestions(suggestions, word);

    suggestions.resize(5);
    return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, string word) const{
    int size = word.size();
    vector<string> trigrams;
    string trigram ="";
    for (unsigned int i = 0; i < word.size() - 2; i++) {
        string trigram ="";
        char c[] = {word.at(i), word.at(i + 1), word.at(i + 2)};
        trigram += c[0];
        trigram += c[1];
        trigram += c[2];
        trigrams.push_back(trigram);
    }


    vector<Word> sug = words[size-1];
    if(size < 25) {
        vector<Word> b = words[size];
        sug.insert(sug.end(), b.begin(), b.end());
    }

    if(size - 2 >= 0) {
        vector<Word> a = words[size -2];
        sug.insert(sug.end(), a.begin(), a.end());
    }



    for(Word w: sug) {
        if(w.get_matches(trigrams) >= trigrams.size()/2) {
            suggestions.push_back(w.get_word());
            //cout << w.get_word();
            //cout << "\n";
        }
    }





}




void Dictionary::rank_suggestions(std::vector<std::string> &suggestions, std::string word) const {

    vector<pair<string, int>> pairs;

    for(string s: suggestions) {

        int cost = calcLeven(s, word);
        pair<string,int> p(s, cost);
        pairs.push_back(p);



    }
    //std::sort(pairs.begin(), pairs.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        //return left.second < right.second;

    //});


    //std::sort (std::begin(pairs), std::end(pairs));
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<string,int> &left, const std::pair<string,int> &right) {
        return left.second < right.second;
    });

    //for(pair<string, int> p: pairs) {
     //  cout << p.second << endl;
    //}



    for(unsigned int i = 0; i < suggestions.size(); i++) {
        suggestions.at(i) = pairs.at(i).first;
    }



}

int Dictionary::calcLeven(std::string suggestion, std::string word) const{
    int d[26][26];

    for(unsigned int i = 0; i < 26; ++i) {
        for(unsigned int j = 0; j < 26;++j) {
            d[i][j] = 0;
        }
    }
    d[0][0] = 0;
    for(unsigned int i = 1; i <= suggestion.length(); ++i) {
        d[i][0] = i;
    }

    for(unsigned int i = 1; i <= word.length(); ++i) {
        d[0][i] = i;  //kan breaka
    }



    int substitutionCost = 0;
    for(unsigned int i = 1; i <= suggestion.length();++i) {
        for(unsigned int j = 1; j <= word.length();++j) {
            if(suggestion.at(i-1) == word.at(j-1)) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            d[i][j]= min(min(d[i-1][j] + 1, d[i][j-1] +1), d[i-1][j-1] + substitutionCost);



        }
    }
    /*for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    //cout << d[suggestion.length()][word.length()];
    return d[suggestion.length()][word.length()];

}








