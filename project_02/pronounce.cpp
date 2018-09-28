/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2 Phase 1

1) Take user input and capitalize it
2) Loop through the text file
3) For each line, split line on spaces and compare the beforestring to the user's input
4) If the beforestring and user input match, then print the afterstring
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
  std::ifstream file("cmudict.0.7a.txt");
  
  string word;
  cin >> word;
  capitalize(word);
  cout << "\n";

  string line, s, pronunciation;
  while (getline(file, line)) {
    splitOnSpace(line, s, pronunciation);
    if (word == s) {
      cout << "Pronunciation    :" << pronunciation << "\n";
      return 0;
    }
  }
  
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
