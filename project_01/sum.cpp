/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: Project1A

This program takes in multiple user inputs and sums them together.
*/

#include <iostream>

int main() {
  // Variables
  std::string s;
  int total = 0;

  while(std::cin >> s) { // While the reading operation is a success
    //std::cout << s << "\n";  // print the read word
    
    // Convert string to int and add to total sum
    total += std::stoi(s);
  }

  std::cout << total << "\n";
  
  return 0;
}
