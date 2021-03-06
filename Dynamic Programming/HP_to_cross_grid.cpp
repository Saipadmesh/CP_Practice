// A grid of numbers is given. If we need to step on that cell, the number in
// that cell is the amount of HP deducted or added, based on the sign. Find the
// minimum number of HP required to reach the top left corner of the array
// from the bottom right corner of the array.
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int minHP(int **arr, int m, int n) {
  int minPoints[m][n];
  minPoints[m - 1][n - 1] =
      (arr[m - 1][n - 1] > 0) ? 1 : abs(arr[m - 1][n - 1]) + 1;
  for (int i = m - 2; i >= 0; i--) {
    minPoints[i][n - 1] = max(minPoints[i + 1][n - 1] - arr[i][n - 1], 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    minPoints[m - 1][i] = max(minPoints[m - 1][i + 1] - arr[m - 1][i], 1);
  }

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      int pointsForExit = min(minPoints[i + 1][j], minPoints[i][j + 1]);
      minPoints[i][j] = max(1, pointsForExit - arr[i][j]);
    }
  }

  return minPoints[0][0];
}

int main() {
  int m, n;
  cin >> m;
  cin >> n;
  int **arr = new int *[m];
  for (int i = 0; i < m; i++) {
    arr[i] = new int[n];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  cout << minHP(arr, m, n);
}