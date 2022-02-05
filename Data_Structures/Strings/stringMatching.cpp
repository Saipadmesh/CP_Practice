#include "string"
#include <iostream>
using namespace std;

bool match(char *first, char *second) {
  if (*first == '\0' && *second == '\0') {
    return true;
  }

  if (*first == '*' && *(first + 1) != '\0' && *second == '\0') {
    return false;
  }
  if (*first == '?' || *first == *second) {
    return match(first + 1, second + 1);
  }
  if (*first == '*') {
    return match(first + 1, second) || match(first, second + 1);
  }
  return false;
}
int main() {

  bool ans = match((char *)"Sai?", (char *)"Saip");
  if (ans) {
    cout << "Matches" << endl;
  } else {
    cout << "Does not match" << endl;
  }
}