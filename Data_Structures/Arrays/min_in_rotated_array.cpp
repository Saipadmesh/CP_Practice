#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Modify binary search. Compare middle element with left and right pointers. If
// mid is greater than both, move the pointers depending on which value is
// greater. Else compare mid with mid+1 element and move the left if mid is
// higher, or move the right to mid.
int findMin(vector<int> &nums) {
  int n = nums.size();
  int currMin = INT_MAX;
  int left = 0, right = n - 1;
  while (left < right) {
    int mid = floor((left + right) / 2);
    if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
      // if left>right, the min element is on the right. Otherwise it is on the
      // left.
      if (nums[left] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      // if mid is greater than next element, chances are the min element is
      // mid+1.
      if (nums[mid] > nums[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
  }
  return nums[left];
}

int main() {
  vector<int> nums = {3, 1, 2};
  // vector<int> nums = {7, 1, 2, 3, 4, 5, 6};
  // { 3, 4, 5, 6, 7, 1, 2}
  // {2, 3, 4, 5, 6, 7, 1}
  int ans = findMin(nums);
  cout << ans << endl;
}