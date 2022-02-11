// String matching when wildcard characters are present in one string
// * --> Matches with 0 or more instances of any character or set of characters.
// ? --> Matches with any one character.
#include "string"
#include <iostream>
using namespace std;

// recursive funtion to match the strings.
bool match(char *first, char *second) {
  // if both pointers reach end of string, they're a match.
  if (*first == '\0' && *second == '\0') {
    return true;
  }
  // If there is a *, and the next character is EOS in one string, but the other
  // string has already reached EOS, return false.
  if (*first == '*' && *(first + 1) != '\0' && *second == '\0') {
    return false;
  }
  // If char is ?, one character is matched, move both pointers and call
  // recursive function.
  if (*first == '?' || *first == *second) {
    return match(first + 1, second + 1);
  }
  // If the char is *, we can either consider the current char in second string
  // and move the first pointer, or ignore it.
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