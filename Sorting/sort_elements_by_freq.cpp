#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct element {
  int count, index, val;
  void addElement(int index, int count, int val) {
    this->count = count;
    this->index = index;
    this->val = val;
  }
  void printElement() { cout << this->index; }
};

bool compare(element e1, element e2) {
  if (e1.count == e2.count) {
    return e1.index > e2.index;
  }
  return e1.count > e2.count;
}

void merge(int arr[], int left, int middle, int right) {
  int subArray1 = middle - left + 1, subArray2 = right - middle;
  int *leftArray = new int[subArray1];
  int *rightArray = new int[subArray2];

  for (int i = 0; i < subArray1; i++) {
    leftArray[i] = arr[left + i];
  }
  for (int j = 0; j < subArray2; j++) {
    rightArray[j] = arr[middle + j + 1];
  }

  int indexOfSubArray1 = 0, indexOfSubArray2 = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2) {
    if (leftArray[indexOfSubArray1] < rightArray[indexOfSubArray2]) {
      arr[indexOfMergedArray] = leftArray[indexOfSubArray1];
      indexOfSubArray1++;
    } else {
      arr[indexOfMergedArray] = rightArray[indexOfSubArray2];
      indexOfSubArray2++;
    }
    indexOfMergedArray++;
  }
  while (indexOfSubArray1 < subArray1) {
    arr[indexOfMergedArray] = leftArray[indexOfSubArray1];
    indexOfSubArray1++;
    indexOfMergedArray++;
  }
  while (indexOfSubArray2 < subArray2) {
    arr[indexOfMergedArray] = rightArray[indexOfSubArray2];
    indexOfSubArray2++;
    indexOfMergedArray++;
  }
}

void mergeSort(int arr[], int begin, int end) {
  if (begin >= end) {
    return;
  }

  int middle = begin + (end - begin) / 2;
  mergeSort(arr, begin, middle);
  mergeSort(arr, middle + 1, end);
  merge(arr, begin, middle, end);
}

void sort_freq(int arr[], int n) {

  mergeSort(arr, 0, n - 1);

  vector<element> elements;
  int currelement = arr[0], count = 0, currIndex = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == currelement) {
      count++;
    } else {
      element e;
      e.addElement(currIndex, count, currelement);
      elements.push_back(e);

      currelement = arr[i];
      currIndex = i;
    }
  }
  sort(elements.begin(), elements.end(), compare);
  for (auto ip = elements.begin(); ip != elements.end(); ip++) {

    for (int i = 1; i <= ip->count; i++) {
      cout << ip->val << " ";
    }
  }
}

int main() {
  int arr[] = {2, 2, 2, 2, 6, 6, 4, 8, 8, 8, 9, 9, 9, 9, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort_freq(arr, n);
}
