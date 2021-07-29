#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool getUnique(vector<int> a, vector<int> b) {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

void print_Vector(vector<vector<int>> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    for (auto it = ip->begin(); it != ip->end(); it++) {
      int a = *it;
      cout << a << ",";
    }
    cout << endl;
  }
}

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (i != 0 && nums[i] == nums[i - 1])
      continue;
    if (nums[i] > 0)
      break;
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
      if (nums[i] + nums[l] + nums[r] == 0) {
        vector<int> v = {nums[i], nums[l], nums[r]};
        if (nums[i] == -3 && nums[l] == -1 && nums[r] == 4) {
          cout << "entered array" << endl;
        }
        ans.push_back(v);
        l++;
        r--;
        while (l < r && nums[l] == nums[l - 1]) {
          l++;
        }

      } else if (nums[i] + nums[l] + nums[r] > 0) {
        r--;
      } else {
        l++;
      }
    }
  }
  print_Vector(ans);
  auto it = unique(ans.begin(), ans.end(), getUnique);
  ans.resize(distance(ans.begin(), it));
  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
  vector<vector<int>> ans = threeSum(nums);
  cout << ans.size() << endl;
  print_Vector(ans);
}