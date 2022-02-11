// Given two strings str1 and str2 and below operations that can performed on
// str1. Find minimum number of edits (operations) required to convert ‘str1’
// into ‘str2’.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// helper function to get the minimum of 3 numbers
int getMin(int x, int y, int z) { return min(x, min(y, z)); }

int getEditDistance(string s, string t) {
  // 2D DP table of size equal to 1+sizes of the two strings.
  int m = s.length(), n = t.length();
  int dp[m + 1][n + 1];
  // Nested loop to traverse entire array in a top-down manner
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      // Fill the first row and column with their index value: (0..m) (0..n)
      if (j == 0) {
        dp[i][j] = i;
      } else if (i == 0) {
        dp[i][j] = j;
      }
      // If the previous character is same in both strings, copy the value of
      // the diagonal cell to the current cell.
      else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      // If there is a difference in the previous character in both string, for
      // the current cell get the minimum between the value in the cell above
      // it, left of it, and diagonal to it. Add one to the value and store it.
      else {
        dp[i][j] = 1 + getMin(dp[i - 1][j],     // Delete
                              dp[i - 1][j - 1], // Replace
                              dp[i][j - 1]);    // Insert
      }
    }
  }
  return dp[m][n];
}

int main() {
  string s = "abc";
  string t = "bac";
  int ans = getEditDistance(s, t);
  cout << "Edit distance is " << ans << endl;
}