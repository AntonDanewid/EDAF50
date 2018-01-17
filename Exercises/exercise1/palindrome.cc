/*
 * Explain the output of the following program.
 */

#include "point.h"
#include <string>
#include <iostream>

using namespace std;

bool is_palindrome(const string& s) {
	string::size_type first = 0;
	string::size_type last = s.size() - 1;
	while (last > first  && s[first] == s[last]) {
		first++;
		last--;
	}
	return last <= first;
}

int main() {
	cout << "Type a word: ";
	string word;
	while (cin >> word) {
		cout << word << " is ";
		if (!is_palindrome(word)) {
			cout << "not ";
		}
		cout << "a palindrome" << endl;
		cout << "Type another word: ";
	}
}



