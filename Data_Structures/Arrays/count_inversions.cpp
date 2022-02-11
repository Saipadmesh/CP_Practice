#include <iostream>
#include <ostream>
using namespace std;
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
// Count number of inversions required to sort the array without actually
// sorting it

// helper function to print array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge(int arr[], int start, int mid, int end, int &count) {
  // Find left and right subarray sizes
  int maxLeftArrSize = mid - start + 1;
  int maxRightArrSize = end - mid;

  // create temp subArrays to copy elements

  // cout << "Left: ";
  int tempLeftArray[maxLeftArrSize], tempRightArray[maxRightArrSize];
  for (int i = 0; i < maxLeftArrSize; i++) {
    tempLeftArray[i] = arr[start + i];
    // cout << tempLeftArray[i] << " ";
  }
  // cout << endl;
  // cout << "Right: ";
  for (int j = 0; j < maxRightArrSize; j++) {
    tempRightArray[j] = arr[mid + 1 + j];
    // cout << tempRightArray[j] << " ";
  }
  // cout << endl;

  int i = 0, j = 0;

  // Single loop which runs until one of the current indices (i or j) reaches
  // the end of the corresponding left or right subArray.
  while (j < maxRightArrSize && i < maxLeftArrSize) {
    // If L[i]>R[j] it means that there is an inversion as in the whole array,
    // i<j as i is index of left subArray.

    if (tempLeftArray[i] > tempRightArray[j]) {
      // increase count by leftArraySize-i (the only tricky part).

      // Assume that we sort the two sub arrays in one merge() call. Then if
      // L[i]>R[j],all elements after i in L will be greater than R[j] and will
      // count as inversions.
      count += maxLeftArrSize - i;
      // cout << "Count: " << count << endl;
      j++;
    }
    if (tempLeftArray[i] <= tempRightArray[j]) {
      i++;
    }
  }
  // cout << "-------------------" << endl;
}

// Similar to merge sort. Find middle element and split array into two in each
// recursive call.
void countInversions(int arr[], int start, int end, int &count) {
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  countInversions(arr, start, mid, count);
  countInversions(arr, mid + 1, end, count);
  merge(arr, start, mid, end, count);
};

int main() {
  int arr[] = {1, 20, 6, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Array: ";
  printArray(arr, n);
  int count = 0;
  countInversions(arr, 0, n - 1, count);
  cout << "Number of inversions is " << count << endl;
  return 0;
}