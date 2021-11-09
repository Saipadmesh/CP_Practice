#include <iostream>
using namespace std;

void sort(int arr[], int left, int mid, int right, int &count) {
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

void merge(int arr[], int left, int mid, int right, int &count) {
  int begin = left, end = mid + 1;
  while (begin <= mid && end <= right) {
    if (arr[begin] > 2 * arr[end]) {
      count += (end - begin + 1);
      begin++;

    } else {
      end++;
    }
  }
  sort(arr, left, mid, right, count);
}

void mergeSort(int arr[], int begin, int end, int &count) {
  if (begin >= end) {
    return;
  }
  int middle = (end + begin) / 2;
  mergeSort(arr, begin, middle, count);
  mergeSort(arr, middle + 1, end, count);
  merge(arr, begin, middle, end, count);
  cout << "count: " << count << endl;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int solution(int arr[], int n) {
  int count = 0;
  mergeSort(arr, 0, n - 1, count);
  return count;
}

int main() {

  int N;
  cin >> N;
  int arr[N];

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int count = solution(arr, N);
  cout << count;
}