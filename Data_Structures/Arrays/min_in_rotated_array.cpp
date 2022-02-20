#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums) {
  int n = nums.size();
  int currMin = INT_MAX;
  int left = 0, right = n - 1;
  while (left < right) {
    int mid = floor((left + right) / 2);
    if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
      if (nums[left] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
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