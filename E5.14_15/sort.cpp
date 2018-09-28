/*
Author: Marcus Ng
Course: CSCI-135
Instructor: Maryash
Assignment: E5.14, E5.15

E.14
Swaps values of a and b if a is greater than b, else unchanged

E.15
Swaps values and arranges them in ascending order
*/

#include <iostream>

void sort2(int&, int&);
void sort3(int&, int&, int&);

int main() {
  int u = 2;
  int v = 3;
  int w = 4;
  int x = 1;
  std::cout << "E.14\n";
  std::cout << "u: " << u << ", v: " << v << "\n";
  sort2(u, v);
  std::cout << "u: " << u << ", v: " << v << "\n";
  std::cout << "w: " << w << ", x: " << x << "\n";
  sort2(w, x);
  std::cout << "w: " << w << ", x: " << x << "\n";

  v = 3;
  w = 4;
  x = 1;
  std::cout << "\nE.15\n";
  std::cout << "v: " << v << ", w: " << w << ", x: " << x << "\n";
  sort3(v, w, x); // v is now 1, w is now 3, x is now 4
  std::cout << "v: " << v << ", w: " << w << ", x: " << x << "\n";
  
  return 0;
}

// E5.14
void sort2(int& a, int& b) {
  if (a > b) {
    // Store b in temp var
    int tmp = a;
    // Swap
    a = b;
    b = tmp;
  }
}

// E5.15
void sort3(int& a, int& b, int& c) {
  // Sort in ascending order
  if (a > b) {
    sort2(a, b);
  }
  if (b > c) {
    sort2(b, c);
  }
  if (a > c) {
    sort2(a, c);
  }
  if (a > b) {
    sort2(a, b);
  }
}
