#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}

void printVector(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}
void minCoins(int coins[], int n, int value, vector<int> ans, int index,
              vector<int> &total_solutions) {

  if (value == 0) {
    total_solutions.push_back(ans.size());
    return;
  }
  if (value < 0) {
    return;
  }
  for (int j = index; j < n; j++) {
    if (coins[j] <= value) {
      ans.push_back(coins[j]);
      minCoins(coins, n, value - coins[j], ans, j, total_solutions);
      ans.pop_back();
    }
  }
}
int main() {
  srand(time(NULL));
  int n, value;
  vector<int> ans, total_solutions;
  cin >> n;
  int coins[n];
  for (int i = 0; i < n; i++) {
    coins[i] = (rand() % 50) + 1;
    // cin >> coins[i];
  }
  sort(coins, coins + n);
  value = (rand() % 500) + 1;
  // cin >> value;
  auto start = chrono::high_resolution_clock::now();
  cout << "Value: " << value << endl;
  cout << "Coin array:";
  printArray(coins, n);
  // cout << "Minimum number of coins required is ";
  minCoins(coins, n, value, ans, 0, total_solutions);
  sort(total_solutions.begin(), total_solutions.end());
  int op = (total_solutions.size() != 0) ? total_solutions[0] : -1;
  cout << "Minimum number of coins required is " << op << endl;
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;
}