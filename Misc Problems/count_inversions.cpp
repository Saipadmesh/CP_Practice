#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
  int subArray1 = mid - 1;
  int subArray2 = right;

  int i = left, j = mid, k = left, count = 0;

  // sort and merge into larger array
  while (i <= subArray1 && j <= subArray2) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    }

    else {
      temp[k++] = arr[j++];
      count += (mid - i);
    }
  }
  // If elements are remaining in the left sub array, add them to the merged
  // array
  while (i <= subArray1) {
    temp[k++] = arr[i++];
  }

  // Same but with right sub array
  while (j <= subArray2) {
    temp[k++] = arr[j++];
  }
  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return count;
}

int mergeSort(int arr[], int temp[], int begin, int end) {
  if (begin >= end) {
    return 0;
  }
  int middle = (end + begin) / 2, count = 0;
  count += mergeSort(arr, temp, begin, middle);
  count += mergeSort(arr, temp, middle + 1, end);
  count += merge(arr, temp, begin, middle + 1, end);
  return count;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // int arr[] = {2, 4, 5, 1, 3, 6, 8, 7};
  int arr[] = {22, 64, 52, 99, 89, 10, 88, 93, 92, 85, 94, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  int temp[n];
  cout << "Before sorting: ";
  printArray(arr, n);
  int count = mergeSort(arr, temp, 0, n - 1);
  cout << "After sorting: ";
  printArray(temp, n);
  cout << "Number of inversions: " << count << endl;

  return 0;
}