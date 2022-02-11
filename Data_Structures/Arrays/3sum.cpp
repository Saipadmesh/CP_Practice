// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Helper Function to check whether a triplet is unique or not, to exclude
// duplicates.
bool getUnique(vector<int> a, vector<int> b) {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

void print_Vector(vector<vector<int>> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {
    cout << "[";
    for (auto it = ip->begin(); it != ip->end(); it++) {
      int a = *it;
      cout << a << ",";
    }
    cout << "], ";
  }
  cout << endl;
}

// Function to get a list of triplets whose sum is 0.
vector<vector<int>> threeSum(vector<int> &nums) {
  // List of triplets
  vector<vector<int>> ans;
  // Sort the input numbers
  sort(nums.begin(), nums.end());
  // Loop through elements
  for (int i = 0; i < nums.size(); i++) {
    // If the same element appears consecutively, skip the iteration.
    if (i != 0 && nums[i] == nums[i - 1])
      continue;
    // If the number is positive, it means that all elements to the right will
    // be positive, so we can break out.
    if (nums[i] > 0)
      break;
    // We use two pointers, one starting from left, another from right, and move
    // them towards the middle.
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
      // if the sum of three numbers is 0, the triplet is considered and the
      // pointers are moved closer by one step.
      if (nums[i] + nums[l] + nums[r] == 0) {
        vector<int> v = {nums[i], nums[l], nums[r]};
        ans.push_back(v);
        l++;
        r--;
        // If there are identical elements, we can skip them.
        while (l < r && nums[l] == nums[l - 1]) {
          l++;
        }

      }
      // Since array is sorted, if the sum is greater, we can reduce the right
      // pointer by 1 and check the lesser positive number.
      else if (nums[i] + nums[l] + nums[r] > 0) {
        r--;
      }

      // If the sum is less than 0, we can simply move the left pointer one step
      // forward.
      else {
        l++;
      }
    }
  }
  // Find unique elements of the vector
  auto it = unique(ans.begin(), ans.end(), getUnique);
  // Resize the vector and fit only the unique elements.
  ans.resize(distance(ans.begin(), it));
  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
  vector<vector<int>> ans = threeSum(nums);
  cout << ans.size() << endl;
  print_Vector(ans);
}