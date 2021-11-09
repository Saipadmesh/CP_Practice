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

  int DP[value + 1];
  int m = value + 1;
  for (int i = 0; i < m; i++) {
    DP[i] = 1000000;
  }
  DP[0] = 0;
  for (int v = 0; v < m; v++) {

    for (int j = 0; j < n; j++) {
      if (coins[j] <= v) {

        DP[v] = min(DP[v], 1 + DP[v - coins[j]]);
      }
    }
  }
  // printArray(DP, m);
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