/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: HW4.6

The program takes in two units (in, cm, m) and a value by the user
and prints out the converted value with the unit.
*/

#include <iostream>
#include <string>

int main() {
   bool done = false;
   std::string unit1 = "";
   std::string unit2 = "";
   double factor1 = 0; // conversion factor from first unit to cm
   double factor2 = 0; // conversion factor from cm to second unit
   
   while (!done) {
      bool again = false; // true to repeat the same conversion
      std::cout << "From unit (in, cm, m, again, quit): \n";
      std::string command;
      std::cin >> command;

      // FIrst factor
      if (command == "in") {
	 factor1 = 2.54; 
	 unit1 = command;
      }
      else if (command == "cm") {
	 factor1 = 1;
	 unit1 = command;
      }
      else if (command == "m") {
	 factor1 = 100;
	 unit1 = command;
      }
      else if (command == "again") {
	 again = true;
      }
      else if (command == "quit") {
	 done = true;
      }
      else {
	 std::cout << "Sorry, unknown unit. \n";
      }

      // Second factor
      if (factor1 != 0 && !again && !done) {
	 std::cout << "To unit: \n";
	 std::cin >> unit2;
	 if (unit2 == "in") {
	    factor2 = 1.0 / 2.54;
	 }
	 else if (unit2 == "m") {
	    factor2 = 1.0 / 100;
	 }
	 else if (unit2 == "cm") {
	    factor2 = 1;
	 }
	 else {
	    std::cout << "Sorry, unknown unit. \n";
	 }
      }

      if (factor1 != 0 && factor2 != 0 && !done) {
	 // Read value to be converted
	 double value;
	 std::cin >> value;
	 // Convert and print result
	 std::cout << value << " " << unit1 << " = " 
		   << value * factor1 * factor2 << " " << unit2 << "\n";
      }
      
   }

   return 0;
}
