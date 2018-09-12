/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: Project1B

This program evaluates a user given expression with addition and subtraction.
*/

#include <iostream>

int main() {
   // Variables
   char c;
   int num = 0, total = 0, sign = 1;

   while(std::cin >> c) { // While the reading operation is a success
      //std::cout << c << "\n";  // print the read word
      // Make number
      if (c != '+' && c != '-') {
	 // Shift number, add int c to one's place, subtract ascii (48)
	 num = num * 10 + static_cast<int>(c) - '0';
	 //std::cout << num << "\n";
      } else {

	 // Add/subtract number to/from total
	 total += num * sign;

	 // Check sign
	 if (c == '+') {
	    sign = 1; // Positive
	 } else if (c == '-') {
	    sign = -1; // Negative
	 }

	 // Reset num
	 num = 0;
      }
   }

   // Add/subtracts last number based on operator
   total += num * sign;
   
   std::cout << total << "\n";
  
   return 0;
}
