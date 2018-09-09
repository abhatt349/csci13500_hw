/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: HW4.2

This program reverses any user inputted integer.
*/

#include <iostream>

int main() {
  // Variables
  int n, reversed = 0;
  
  // User Input
  std::cout << "Enter any integer: \n";
  std::cin >> n;
  
  // Print the digits of n in reverse
  while (n != 0) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }

  std::cout << reversed << "\n";
  
  return 0;
}
