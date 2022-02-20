#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void print_Vector(vector<int> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    int a = *ip;
    cout << a << ",";
  }
  cout << endl;
}
// Similar to Kadane algo for addition but an find the min at each step. Compare
// 3 values (curr,max*curr,min*curr) for max and min at each step and update
// totalMax if max at that step is higher.
int maxProductSubarray(vector<int> &nums) {
  int max_ending_here = nums[0];
  int min_ending_here = nums[0];
  int maxTotal = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    max_ending_here =
        max(nums[i], max(max_ending_here * nums[i], min_ending_here * nums[i]));
    min_ending_here =
        min(nums[i], min(max_ending_here * nums[i], min_ending_here * nums[i]));
    maxTotal = max(max_ending_here, maxTotal);
  }
  return maxTotal;
}

int main() {
  vector<int> arr = {1, 3, 0, -2, -4};
  int ans = maxProductSubarray(arr);
  cout << ans << endl;
}