#include <iostream>
#include <stdlib.h>

using std::cout;
using std::string;

void reverse(char s[]);

int main() {
  char s[] = "Harry";
  reverse(s);
  cout << s << "\n";
  return 0;
}

void reverse(char s[]) {
  char reverse[strlen(s)];
  for (int i = 0; i < strlen(s); i++) {
    reverse[i] = s[strlen(s) - 1 - i];
  }
  strcpy(s, reverse);
}
