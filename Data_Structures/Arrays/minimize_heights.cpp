#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int minimizeHeight(int arr[], int n, int k) {
  sort(arr, arr + n);
  int ans = arr[n - 1] - arr[0];
  int minimum = arr[0] + k, maximum = arr[n - 1] - k;
  int min1, max1;
  for (int i = 0; i < n - 1; i++) {
    min1 = min(minimum, arr[i + 1] - k);
    max1 = max(maximum, arr[i] + k);
    if (min1 < 0) {
      continue;
    }
    ans = min(max1 - min1, ans);
  }
  return ans;
}

int main() {
  int num[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
  int k = 5;
  int length = sizeof(num) / sizeof(num[0]);
  int sum = minimizeHeight(num, length, k);
  cout << sum << endl;
}
