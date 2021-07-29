#include <iostream>
using namespace std;

// Loop invariant: arr[0..i-1] is always sorted.
void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {4, 2, 6, 7, 1, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertion_sort(arr, n);
  printArray(arr, n);
}