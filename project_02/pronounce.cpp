/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2 Phase II

1) Loop through the text file
2) When the word’s pronunciation is different from another word’s pronunciation, 
find the index where the pronunciations are different and take the substrings of
the index to the end for both strings
3) Split both pronunciations on spaces and compare the afterstring
3) If the afterstrings are the same, then append the new word to a string
4) Print out the new words when the loop ends

*/

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cin;
using std::cout;

void capitalize(string &);
void splitOnSpace(string s, string &, string &);

int main() {
  std::ifstream file("cmudict.0.7a");

  bool found = false;
  string word, pron;
  cin >> word;
  capitalize(word);
  cout << "\n";

  // Phase I
  string line, s, pronunciation;
  while (getline(file, line) && !found) {
    splitOnSpace(line, s, pronunciation);
    if (word == s) {
      pron = pronunciation;
      cout << "Pronunciation    :" << pronunciation << "\n";
      found = true;
    }
  }

  // If word not found
  if (!found) {
    cout << "Not found!\n";
    return 0;
  }

  file.clear();
  file.seekg(0, file.beg);

  // Phase II
  string identical = "";
  while (getline(file, line)) {
    splitOnSpace(line, s, pronunciation);
    if (pron == pronunciation && word != s) {
      identical += s + " ";
    }
  }
  cout << "Identical        : " << identical << "\n";

  file.clear();
  file.seekg(0, file.beg);
  
  // Phase III
  string replacePhoneme = "";
  while (getline(file, line)) {
    splitOnSpace(line, s, pronunciation);
    if (pron != pronunciation && word != s) {
      string wordPron = pron;
      string currPron = pronunciation;
      int length = wordPron.length();
      int index = 0;
      bool different = false;
      
      // Length of shorter string
      if (wordPron.length() > currPron.length()) {
	length = currPron.length();
      }

      // Find index where pronunciations are different
      for (int i = 0; i < length; i++) {
	if (wordPron.at(i) != currPron.at(i) && !different) {
	  index = i;
	  different = true;
	}
      }

      if (different) {
	// Substring to end
	wordPron = wordPron.substr(index);
	currPron = currPron.substr(index);

	string beforeWordPron, afterWordPron, beforeCurrPron, afterCurrPron;
	splitOnSpace(wordPron, beforeWordPron, afterWordPron);
	splitOnSpace(currPron, beforeCurrPron, afterCurrPron);

	if (afterWordPron == afterCurrPron) {
	  replacePhoneme += s + " ";
	}
      }
    }
  }
  cout << "Replace Phoneme  : " << replacePhoneme << "\n";
  
  return 0;
}

void capitalize(string & s) {
  string upper;
  int i = 0;
  while (i < s.length()) {
    int c = std::toupper(s[i]);
    upper += static_cast<char>(c);
    i++;
  }
  s = upper;
}

void splitOnSpace(string s, string & before, string & after) {
  // reset strings
  before = ""; 
  after = "";
  // accumulate before space
  int i = 0;
  while (i < s.size() && not isspace(s[i])) { before += s[i]; i++; }
  // skip the space
  i++;
  // accumulate after space
  while (i < s.size()) { after += s[i]; i++; }
}
