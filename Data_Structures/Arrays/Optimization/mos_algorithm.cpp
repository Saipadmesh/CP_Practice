#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// A query contains sum of nmbers in an array between two indices.
// MO's algorithm processes multiple queries at once in O((m+n)*sqrt(n)) instead
// of O(m*n)

// The idea is to preprocess all queries and use the sum of previous queries in
// the next query.

int block;
struct Query {
  int L, R;
};

bool compareQuery(Query q1, Query q2) {
  // Both queries belong to different blocks.
  // eg: 0 to sqrt(n)-1 and sqrt(n) to 2*sqrt(n)-1
  if (q1.L / block != q2.L / block) {
    return (q1.L / block < q2.L / block);
  }
  // Both queries exist within a block
  return q1.R < q2.R;
}

void print_mos_algo(int arr[], int n, Query q[], int m) {
  // Split array into blocks of size sqrt(n)
  block = (int)sqrt(n);
  // sort queries based on the left index/blockSize or the min right index
  sort(q, q + m, compareQuery);
  // variables for finding answer to the current query. Note that current Right
  // also starts from 0.
  int currL = 0, currR = 0, sum = 0;
  // Loop through queries
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
    cout << "Sum of indices [" << L << ", " << R << "] is " << sum << endl;
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