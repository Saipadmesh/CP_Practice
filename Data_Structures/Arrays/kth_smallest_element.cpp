// Find the kth minimum element in an array

// Multiple ways to answer this question, will try to attempt all of them
#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// Using set from C++ stl which is implemented using a BST
int kthSmallest_set(int arr[], int l, int r, int k) {
  // sorts integers during input
  set<int> s(arr, arr + r + 1);
  set<int>::iterator itr = s.begin();
  // move to the position (k-1)
  advance(itr, k - 1);
  return *itr;
}
// helper function to make a min heap
struct compares {
  bool operator()(const long &a, const long &b) const { return a < b; }
};
// Using STL Priority Queue
int kthSmallest_heap(int arr[], int n, int k) {
  // STL priority queue is usually implemented using a max_heap. Here, the use
  // of greater<int> makes sure that it is implemented as a min_heap.
  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < n; i++) {
    // min heap makes sure that the smallest value is always on top.
    heap.push(arr[i]);
  }
  for (int i = 0; i < k - 1; i++) {
    heap.pop();
  }
  return heap.top();
}

// get Pivot for quick sort algo.
int get_pivot(int nums[], int begin, int end) {
  // the first element in the subarray is considered as the pivot initially.
  int p_index = begin, pivot = nums[begin];
  for (int i = begin + 1; i <= end; i++) {
    // if a number in the array is less than pivot, push pivot to the right by
    // 1, and push the number to the left of the pivot
    if (nums[i] < pivot) {
      nums[p_index] = nums[i];
      nums[i] = nums[p_index + 1];
      nums[p_index + 1] = pivot;
      p_index++;
    }
  }
  return p_index;
}
// Implemented using quick sort algorithm, but the function sorts only till k
// elements are returns the kth smallest element
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