#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int get_pivot(vector<int> &nums, int begin, int end) {
  int p_index = begin, pivot = nums[begin];
  for (int i = begin + 1; i <= end; i++) {
    // if a number in the array is less than pivot, push pivot to the right
    if (nums[i] < pivot) {
      cout << nums[i] << "," << nums[p_index] << "," << nums[p_index + 1]
           << endl;
      nums[p_index] = nums[i];
      nums[i] = nums[p_index + 1];
      nums[p_index + 1] = pivot;
      p_index++;
    }
  }
  return p_index;
}

void quick_sort(vector<int> &nums, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot = get_pivot(nums, begin, end);
  cout << "pivot value: " << pivot << endl;
  cout << "array: " << endl;
  printArray(nums, nums.size());
  quick_sort(nums, begin, pivot - 1);
  quick_sort(nums, pivot + 1, end);
}

int main() {
  vector<int> nums = {2, 5, 1, 3, 6, 4};
  int n = nums.size();
  quick_sort(nums, 0, n - 1);
  cout << "sort done" << endl;
  printArray(nums, n);
}