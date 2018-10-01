/*
Author: Marcus Ng
Instructor: Maryash
Course: CSCI-135
Assignment: E6.7

Reverse a user given array
*/

#include <iostream>

void print_array(int[], int);
void reverse_array(int arr[], int);

using std::cout;

int main() {
  int SIZE = 9;
  int arr[] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
  cout << "Original Array: ";
  print_array(arr, SIZE);
  reverse_array(arr, SIZE);
  cout << "Reversed array: ";
  print_array(arr, SIZE);;
  cout << "\n";
  
  return 0;
}

void print_array(int arr[], int size) {
  int i = 0;
  for (i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void reverse_array(int arr[], int size) {
  int reverse[size];
  int i;
  for (i = 0; i < size; i++) {
    reverse[i] = arr[size - 1 - i];
  }
  for (i = 0; i < size; i++) {
    arr[i] = reverse[i];
  }
}
