#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, s, p, q;
  cin >> n;
  int a[n];
  cin >> s;
  a[0] = s % (int)(pow(2, 31));
  cin >> p >> q;
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] * p + q % (int)(pow(2, 31));
  }
  printArray(a, n);

  return 0;
}