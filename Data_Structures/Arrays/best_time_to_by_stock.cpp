// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you
// cannot achieve any profit, return 0.

#include <iostream>
#include <vector>
using namespace std;

// Use two pointers min and max Index. Third variable to store max profit. If
// price on day(min) higher than day(max), no need to buy, wait till day(max).
// Otherwise, check your previous total profit, and if current profit is higher,
// make it your total profit.
int maxProfit(vector<int> &prices) {
  int minIndex = 0;
  int maxIndex = 1;
  int maxResult = 0;
  int i = 0;
  while (maxIndex < prices.size()) {
    if (prices[minIndex] < prices[maxIndex]) {
      maxResult = (maxResult > prices[maxIndex] - prices[minIndex])
                      ? maxResult
                      : prices[maxIndex] - prices[minIndex];
    } else {
      minIndex = maxIndex;
    }
    maxIndex++;
  }
  return maxResult;
}

int main() {
  vector<int> arr = {2, 4, 1, 2};
  int ans = maxProfit(arr);
  cout << ans << endl;
}