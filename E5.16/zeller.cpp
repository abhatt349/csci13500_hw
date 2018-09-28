/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: E5.16

This program computes the weekday of a given date using Zeller's congruence formula.

d = day of the month
mm = the modified month (3 = March, ... , 12 = December, 13 = January, 14 = February)
w = the weekday (0 = Monday, ... , 6 = Sunday)
year = year (2000, 2018)

w = (d + 5 + (26 * (mm + 1)) / 10 + (5 * (year % 100)) / 4 + (21 * (year / 100)) / 4) % 7
*/

#include <iostream>
#include <string>

using std::string;

string zeller(int, int, int);

int main() {

  zeller(9, 25, 2018); // Tu
  zeller(3, 1, 2018); // Th
  
  return 0;
}

string zeller(int mm, int d, int year) {
  int w;
  w = (d + 5
       + (26 * (mm + 1)) / 10
       + (5 * (year % 100)) / 4
       + (21 * (year / 100)) / 4) % 7;

  switch (w) {
  case 0:
    std::cout << "Monday\n";
    return "Monday";
  case 1:
    std::cout << "Tuesday\n";
    return "Tuesday";
  case 2:
    std::cout << "Wednesday\n";
    return "Wednesday";
  case 3:
    std::cout << "Thursday\n";
    return "Thursday";
  case 4:
    std::cout << "Friday\n";
    return "Friday";
  case 5:
    std::cout << "Saturday\n";
    return "Saturday";
  case 6:
    std::cout << "Sunday\n";
    return "Sunday";
  default:
    std::cout << "Error: Weekday not found\n";
    return "Error: Weekday not found";
  }
  
}
