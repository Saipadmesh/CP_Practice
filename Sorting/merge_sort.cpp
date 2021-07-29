#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int subArray1 = mid - left + 1;
  int subArray2 = right - mid;
  int *tempLeftArray = new int[subArray1], *tempRightArray = new int[subArray2];

  // copy data to temp arrays
  for (int i = 0; i < subArray1; i++) {
    tempLeftArray[i] = arr[left + i];
  }
  for (int j = 0; j < subArray2; j++) {
    tempRightArray[j] = arr[mid + 1 + j];
  }

  int indexOfSubArray1 = 0, indexOfSubArray2 = 0;
  int indexOfMergedArray = left;
  // sort and merge into larger array
  while (indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2) {
    if (tempLeftArray[indexOfSubArray1] <= tempRightArray[indexOfSubArray2]) {
      arr[indexOfMergedArray] = tempLeftArray[indexOfSubArray1];
      indexOfSubArray1++;
    } else {
      arr[indexOfMergedArray] = tempRightArray[indexOfSubArray2];
      indexOfSubArray2++;
    }
    indexOfMergedArray++;
  }
  // If elements are remaining in the left sub array, add them to the merged
  // array
  while (indexOfSubArray1 < subArray1) {
    arr[indexOfMergedArray] = tempLeftArray[indexOfSubArray1];
    indexOfSubArray1++;
    indexOfMergedArray++;
  }

  // Same but with right sub array
  while (indexOfSubArray2 < subArray2) {
    arr[indexOfMergedArray] = tempRightArray[indexOfSubArray2];
    indexOfSubArray2++;
    indexOfMergedArray++;
  }
}

void mergeSort(int arr[], int begin, int end) {
  if (begin >= end) {
    return;
  }
  int middle = (end + begin) / 2;
  mergeSort(arr, begin, middle);
  mergeSort(arr, middle + 1, end);
  merge(arr, begin, middle, end);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {2, 4, 5, 1, 3, 6, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Before sorting: ";
  printArray(arr, n);
  mergeSort(arr, 0, n - 1);
  cout << "After sorting: ";
  printArray(arr, n);
  return 0;
}