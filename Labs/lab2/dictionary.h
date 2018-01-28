#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
    std::unordered_set <std::string> stringSet;
    std::vector<Word> words[25]; // words[i] = the words with i letters,
// ignore words longer than 25 letters

	void add_trigram_suggestions(std::vector<std::string> &suggestions, std::string word) const;
	void rank_suggestions(std::vector<std::string> &suggestions, std::string word) const;
	int  calcLeven(std::string suggestion, std::string word) const;
};

#endif
