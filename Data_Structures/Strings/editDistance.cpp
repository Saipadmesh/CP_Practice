#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getMin(int x, int y, int z) { return min(x, min(y, z)); }

int getEditDistance(string s, string t) {
  int m = s.length(), n = t.length();
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0) {
        dp[i][j] = i;
      } else if (i == 0) {
        dp[i][j] = j;
      } else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + getMin(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]);
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