#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
  // Write your code here.
  deque<int> dq;
  int max = 0;
  for (int i = 0; i < n; i++) {
    int size = dq.size();
    if (max < arr[i]) {
      max = arr[i];
    }
    if (size < k) {
      dq.push_back(arr[i]);
    }
    if (size == k) {
      cout << max << " ";
      if (*dq.begin() == max) {
        dq.pop_front();
        auto it = dq.begin();
        max = 0;
        while (it != dq.end()) {
          if (max < *it) {
            max = *it;
          }
          it++;
        }
      }
    }
  }
}

int main() {

  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}