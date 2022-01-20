#include <iostream>
#include <ostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge(int arr[], int start, int mid, int end, int &count) {
  int maxLeftArrSize = mid - start + 1;
  int maxRightArrSize = end - mid;
  int tempLeftArray[maxLeftArrSize], tempRightArray[maxRightArrSize];
  for (int i = 0; i < maxLeftArrSize; i++) {
    tempLeftArray[i] = arr[start + i];
  }

  for (int j = 0; j < maxRightArrSize; j++) {
    tempRightArray[j] = arr[mid + 1 + j];
  }
  cout << "Left: ";
  printArray(tempLeftArray, maxLeftArrSize);
  cout << "Right: ";
  printArray(tempRightArray, maxRightArrSize);

  int i = 0, j = 0;
  while (j < maxRightArrSize && i < maxLeftArrSize) {
    // cout << "Inside inner sorting loop" << endl;
    if (tempLeftArray[i] > tempRightArray[j]) {
      // cout << "Count in loop: " << count << endl;

      count += maxLeftArrSize - i;
      j++;
      cout << "Count: " << count << endl;
    }
    if (tempLeftArray[i] <= tempRightArray[j]) {
      i++;
    }
  }
  cout << "-----------------" << endl;
}

void countInversions(int arr[], int start, int end, int &count) {
  if (start >= end) {
    // cout << "Done" << endl;
    return;
  }
  // cout << "Inside main fn" << endl;
  int mid = (start + end) / 2;
  countInversions(arr, start, mid, count);
  countInversions(arr, mid + 1, end, count);
  merge(arr, start, mid, end, count);
};

int main() {
  int arr[] = {2, 4, 1, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Array: ";
  printArray(arr, n);
  int count = 0;
  countInversions(arr, 0, n - 1, count);
  cout << count << endl;
  return 0;
}