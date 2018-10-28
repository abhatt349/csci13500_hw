/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2 Phase V

Enter a word to find its pronunciation, words with identical phonemes, 
words with a different phoneme, words with an extra phoneme, 
and words with one less phoneme.
*/

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cin;
using std::cout;

void capitalize(string &);
void splitOnSpace(string s, string &, string &);
bool is_valid(string s);
//void pronunciation(string line, string s, string pronunciation, string word, stirng pron);

int main() {
  std::ifstream file("cmudict.0.7a");

  bool found = false;
  string word, pron;
  cin >> word;
  capitalize(word);
  cout << "\n";

  if (!is_valid(word)) {
    cout << "Not found!\n";
  }
  
  // Phase I
  string line, s, pronunciation;
  while (getline(file, line) && !found) {
    splitOnSpace(line, s, pronunciation);
    if (word == s) {
      pron = pronunciation;
      cout << "Pronunciation    :" << pronunciation << "\n\n";
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

	if (is_valid(s) && afterWordPron == afterCurrPron) {
	  replacePhoneme += s + " ";
	}
      }
    }
  }

  file.clear();
  file.seekg(0, file.beg);
  
  // Phase IV
  string addPhoneme = "";
  while (getline(file, line)) {
    splitOnSpace(line, s, pronunciation);
    // If not the current word
    if (pron != pronunciation && word != s) {
      string wordPron = pron;
      string currPron = pronunciation;
      int length = wordPron.length();
      int index = 0;
      int differences = 0;

      // Length of shorter string
      if (wordPron.length() > currPron.length()) {
	length = currPron.length();
      }

      // Look for first difference
      for (int i = 0; i < length; i++) {
	if (wordPron.at(i) != currPron.at(i) && differences == 0) {
	  index = i;
	  differences += 1;
	}
      }

      string beforeCurrPron, afterCurrPron;
      // Second difference
      if (differences == 1) {
	// Substring to end
	wordPron = wordPron.substr(index);
	currPron = currPron.substr(index);
	
	splitOnSpace(currPron, beforeCurrPron, afterCurrPron);

	// Check for second difference by comparing the rest of the afterCurrPron
	// with the rest of the original word
	if (wordPron != afterCurrPron) {
	  differences += 1;
	}
	
	// If only one difference, then append to addPhoneme
	if (is_valid(s) && differences == 1) {
	  addPhoneme += s + " ";
	}
      }
      
      // Check for phoneme at end
      if (differences == 0 && wordPron == currPron.substr(0, wordPron.length())) {
	// Add 1 to get rid of space
	splitOnSpace(currPron.substr(wordPron.length() + 1), beforeCurrPron, afterCurrPron);
	// No afterstring --> One phoneme extra
	if (is_valid(s) && afterCurrPron == "") {
	  addPhoneme += s + " ";
	}
      }
    }
  }

  file.clear();
  file.seekg(0, file.beg);
  
  // Phase V
  string removePhoneme = "";
  while (getline(file, line)) {
    
    splitOnSpace(line, s, pronunciation);
    // If not the current word
    if (is_valid(s) && pron != pronunciation && word != s) {
      string wordPron = pron;
      string currPron = pronunciation;
      int length = wordPron.length();
      int index = 0;
      string beforeWordPron, afterWordPron, beforeCurrPron, afterCurrPron;
      
      // Length of shorter string
      if (wordPron.length() > currPron.length()) {
	length = currPron.length();
      }

      while (index < length && wordPron.at(index) == currPron.at(index)) {
	index++;
      }

      
      // Substring to end
      wordPron = wordPron.substr(index);

      int i = 0;
      while (i < wordPron.length() && isspace(wordPron.at(i))) {
	i++;
      }
      wordPron = wordPron.substr(i);
     
      splitOnSpace(wordPron, beforeWordPron, afterWordPron);
      afterCurrPron = currPron.substr(index);

      // If after words are the same, then add to removePhoneme
      if (afterWordPron == afterCurrPron) {
	removePhoneme += s + " ";
      }
    }
  }

  cout << "Identical        : " << identical << "\n";
  cout << "Replace Phoneme  : " << replacePhoneme << "\n";
  cout << "Add phoneme      : " << addPhoneme << "\n";
  cout << "Remove phoneme   : " << removePhoneme << "\n";

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

bool is_valid(string s) {
  for (unsigned int i = 0; i < s.length(); i++) {
    if (!((s[i] >= 'A' && s[i] <= 'Z')
	  || s[i] == '\'')) {
      return false;
    }
  }
  return true;
}
  
