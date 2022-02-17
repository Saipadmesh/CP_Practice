#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_Vector(vector<int> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    int a = *ip;
    cout << a << ",";
  }
  cout << endl;
}
// If the indices aren't asked, sort the array, and use two pointers, from start
// and end of array, and move them till sum is found.
vector<int> twoSum_elements(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int ptr1 = 0, ptr2 = nums.size() - 1;
  vector<int> ans;
  while (ptr1 < ptr2) {
    if (nums[ptr1] + nums[ptr2] == target) {
      ans.push_back(nums[ptr1]);
      ans.push_back(nums[ptr2]);
      break;
    } else if (nums[ptr1] + nums[ptr2] > target) {
      ptr2--;
    } else {
      ptr1++;
    }
  }
  return ans;
}
// If indices are asked, loop through array and use a hashmap with key as arr[i]
// and value as i. Every iteration, find whether target-arr[i] exists as key,
// and if it does, answer is i and map[target-arr[i]]
vector<int> twoSum_index(vector<int> &nums, int target) {
  map<int, int> hashMap;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    if (hashMap.find(target - nums[i]) != hashMap.end()) {
      ans.push_back(i);
      ans.push_back(hashMap[target - nums[i]]);
      break;
    }
    hashMap[nums[i]] = i;
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  vector<int> nums = {3, 2, 4};
  vector<int> ans = twoSum_index(nums, 6);
  print_Vector(ans);
}