/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: E8.3

Opens a file with a user inputted name and takes the average of the 
doubles in the file. If the user inputs an empty string, reprompt
for a new file name.
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

double average(double total, int n);

int main() {
  ifstream file;
  string file_name, line;
  double total, avg;
  int n;

  // Reprompt
  while (file_name.empty()) {
    cout << "Enter a file name: ";
    getline(cin, file_name);
  }

  // Open file
  file.open(file_name.c_str());
  if (file.fail()) {
    cout << "No file found!\n";
    return -1;
  }
  
  // Add up numbers
  double num;
  while (getline(file, line)) {
    num = std::stod(line);
    total += num;
    n++;
  }

  // Average
  avg = average(total, n);
  cout << "\nAverage: " << avg << endl << endl;
  
}

double average(double total, int n) {
  return total / n;
}
