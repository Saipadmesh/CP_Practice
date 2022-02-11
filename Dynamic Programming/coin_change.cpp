// Given a value and a list of coins, find the minimum number of coins required
// whose sum will give the value.

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::chrono;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}
int minCoins(int coins[], int n, int value) {
  // 1D array DP table.
  int DP[value + 1];
  int m = value + 1;
  // Fill the table with v high value for all indices except 0.
  for (int i = 1; i < m; i++) {
    DP[i] = 1000000;
  }
  DP[0] = 0;
  // 2 loops, 1 for dp table and another for coin array.
  for (int v = 0; v < m; v++) {

    for (int j = 0; j < n; j++) {
      // We can't use a coin which has a higher value than the value we want.
      if (coins[j] <= v) {
        // If the value is already less, no need to change. Otherwise, we need 1
        // coin more than the number of coins required for v-coins[j].
        DP[v] = min(DP[v], 1 + DP[v - coins[j]]);
      }
    }
  }
  // If the value hasn't changed, it means that the value cannot be achieved
  // using the given coin set.
  return (DP[value] != 1000000) ? DP[value] : -1;
}
int main() {
  srand(time(NULL));
  int n, value;
  cin >> n;
  int coins[n];
  for (int i = 0; i < n; i++) {
    coins[i] = (rand() % 50) + 1;
  }
  sort(coins, coins + n, greater<int>());
  value = (rand() % 500) + 1;
  auto start = chrono::high_resolution_clock::now();
  cout << "Value: " << value << endl;
  cout << "Coin array:";
  printArray(coins, n);
  cout << "Minimum number of coins required is " << minCoins(coins, n, value)
       << endl;
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;
}