/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: HW4.2

This program reverses a user inputted string.
*/


#include <iostream>
#include <string>

int main() {
  
  // Variables
  std::string s;
  std::string r = "";

  // User Input
  std::cout << "Enter a word: \n";
  std::cin >> s;

  // Reverse the string
  int i = 0;
  while (i < s.length()) {
    std::string c = s.substr(i, 1);
    r = c + r;
    i++;
  }

  std::cout << r << "\n";
  
  return 0;
}
