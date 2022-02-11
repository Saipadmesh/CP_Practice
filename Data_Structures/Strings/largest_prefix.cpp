#include <iostream>
#include <string>
#include <vector>

using namespace std;

string checkPrefix(vector<string> &words) {
  // Start with the first text in the array.
  for (int i = 0; i < words[0].size(); i++) {
    // Get letter at i
    char c = words[0].at(i);
    // Loop for each word in the array
    for (int j = 1; j < words.size(); j++) {
      // If index i is the size of the word at j, or if the character doesn't
      // match, return substring till i.
      if (i == words[j].size() || c != words[j].at(i)) {
        return words[0].substr(0, i);
      }
    }
  }
  // If the loop successfully ends, then the first word is the prefix for every
  // other word
  return words[0];
}

int main() {
  vector<string> words{"flet", "flee", "fleetcode"};
  string prefix = checkPrefix(words);
  cout << prefix << endl;
}