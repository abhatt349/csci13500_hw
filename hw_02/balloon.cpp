/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: HW2

The program calculates the growth of a sphere with user given diameter.
*/

/*

1) Rearrange the following lines of code to produce correct pseudocode for this task:

Prompt for diameter and read user input

volume1 = π × diameter × diameter × diameter / 6
diameter++

volume2 = π × diameter × diameter × diameter / 6
diameter++

volume3 = π × diameter × diameter × diameter / 6

growth = volume2 - volume1
Print growth

growth = volume3 - volume2
Print growth

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  
  const double PI = 3.141592653589793;

  // Variables
  int diameter, volume1, volume2, volume3, growth;

  // Input
  cout << "Diameter: ";
  cin >> diameter;

  // Calculate volume and increaset diameter by 1
  volume1 = PI * diameter * diameter * diameter / 6;
  diameter++;

  volume2 = PI * diameter * diameter * diameter / 6;
  diameter++;

  volume3 = PI * diameter * diameter * diameter / 6;

  // Calculate growth and print
  growth = volume2 - volume1;
  cout << "Increase: " << growth << endl;

  growth = volume3 - volume2;
  cout << "Increase: " << growth << endl;
  
  return 0;
}
