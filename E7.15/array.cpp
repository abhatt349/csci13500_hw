/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: E7.15

Read data from cin and until the user enters 0.
Allocate the correct amount of memory for the array
and copy inputs.
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int * read_data(int & size);

int main() {
  int size = 10;
  int * arr;
  cout << "Enter any integer to add them to the array (0 to stop):\n";
  arr = read_data(size);
  cout << "Size: " << size << endl;
  cout << "Array: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
    if (i == size - 1) {
      cout << endl;
    }
  }

  delete [] arr;
  
  return 0;
}

int * read_data(int & size) {
  int * arr = new int[size];
  int * tmp = new int[size];
  int n;
  int ctr = 0;

  // Populate arrays with 0's
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
    tmp[i] = 0;
  }
  
  while (cin >> n && n != 0) {
    // If size is reached
    if (ctr == size) {
      // Increase size by 10
      size += 10;
      // Copy array
      tmp = new int[size];
      for (int i = 0; i < size; i++) {
	tmp[i] = arr[i];
      }
      arr = new int[size];
      for (int i = 0; i < size; i++) {
	arr[i] = tmp[i];
      }
    }
    // Assign value
    arr[ctr] = n;
    ctr++;
  }

  // Assign correct size
  size = ctr;

  // Copy to new array
  int * ret = new int[size];
  for (int i = 0; i < size; i++) {
    ret[i] = arr[i];
  }

  // Delete old data
  delete [] arr;
  delete [] tmp;
  
  return ret;
}

