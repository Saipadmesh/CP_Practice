// code to implement heap in array
#include <iostream>

using namespace std;

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void insert(int arr[], int n, int currSize) {
  int j;
  int i = j = currSize + 1;
  while (i > 1) {
    i = i / 2;
    if (arr[i - 1] < arr[j - 1]) {
      swap(arr, i - 1, j - 1);
      j = i;
    }
  }
}

void create_Max_heap(int arr[], int n) {
  for (int j = 1; j <= n - 1; j++) {
    insert(arr, n, j);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  create_Max_heap(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}