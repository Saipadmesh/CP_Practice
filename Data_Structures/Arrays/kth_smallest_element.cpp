// Find the kth minimum element in an array

// Multiple ways to answer this question, will try to attempt all of them
// Method Using quick Sort is implemented in Divide and Conquer section (..or is
// it?)
#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

// Using set from C++ stl which is implemented using a BST
int kthSmallest_set(int arr[], int l, int r, int k) {
  set<int> s(arr, arr + r + 1);
  set<int>::iterator itr = s.begin();
  advance(itr, k - 1);
  return *itr;
}

struct compares {
  bool operator()(const long &a, const long &b) const { return a > b; }
};
// Using STL heap
int kthSmallest_heap(int arr[], int l, int r, int k) {
  make_heap(arr, arr + r + 1, compares());
  for (int i = 0; i < k - 1; i++) {
    pop_heap(arr, arr + r + 1);
  }
  return arr[0];
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int get_pivot(int nums[], int begin, int end) {
  int p_index = begin, pivot = nums[end];
  for (int i = begin; i <= end - 1; i++) {
    // if a number in the array is less than pivot, push pivot to the right
    if (nums[i] < pivot) {
      cout << nums[i] << "," << nums[p_index] << "," << nums[p_index + 1]
           << endl;
      swap(&nums[i], &nums[p_index]);
      p_index++;
    }
  }
  swap(&nums[p_index], &nums[end]);
  return p_index;
}

int kthSmallest_quick(int nums[], int begin, int end, int k) {
  if (k <= 0 || k > end - begin + 1) {
    return INT_MAX;
  }
  int pivot = get_pivot(nums, begin, end);

  if (pivot - begin == k - 1) {
    return nums[pivot];
  }
  if (pivot - begin > k - 1) {
    return kthSmallest_quick(nums, begin, pivot - 1, k);
  }
  return kthSmallest_quick(nums, pivot + 1, end, k - pivot + begin - 1);
}

int main() {
  int arr[] = {7, 10, 4, 3, 20, 15};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  int ans = kthSmallest_quick(arr, 0, n - 1, k);
  cout << ans << endl;
}