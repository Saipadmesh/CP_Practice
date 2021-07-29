#include <bits/stdc++.h>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

// A query contains sum of nmbers in an array between two indices.
// MO's algorithm processes multiple queries at once in O((m+n)*sqrt(n)) instead
// of O(m*n)

// We split it into blocks of size sqrt(n) and calculate sum of each block to
// increase efficiency.
int block;
struct Query {
  int L, R;
};

bool compareQuery(Query q1, Query q2) {
  if (q1.L / block != q2.L / block) {
    return (q1.L / block < q2.L / block);
  }
  // if L is same
  return q1.R < q2.R;
}

void print_mos_algo(int arr[], int n, Query q[], int m) {
  block = (int)sqrt(n);
  // sort queries based on the left index or the min index
  sort(q, q + m, compareQuery);
  int currL = 0, currR = 0, sum = 0;

  for (int i = 0; i < m; i++) {
    int L = q[i].L;
    int R = q[i].R;
    // Remove extra elements from previous range
    while (currL < L) {
      sum -= arr[currL];
      currL++;
    }

    // Add elements of current range
    while (currL > L) {
      sum += arr[currL - 1];
      currL--;
    }
    while (currR <= R) {
      sum += arr[currR];
      currR++;
    }

    // Remove elements from the right of previous range
    while (currR > R + 1) {
      sum -= arr[currR];
      currR--;
    }
    cout << "Sum of [" << L << ", " << R << "] is " << sum << endl;
  }
}

int main() {
  int m, n;
  cout << "Enter array size: ";
  cin >> n;
  int arr[n];

  int j = 0;
  for (j = 0; j < n; j++) {
    cin >> arr[j];
  }

  cout << "Enter number of queries: ";
  cin >> m;
  Query q[m];
  int k;
  for (j = 0; j < m; j++) {
    cin >> q[j].L;
    cin >> q[j].R;
  }
  print_mos_algo(arr, n, q, m);
}