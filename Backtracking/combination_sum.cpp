// Given an array of distinct integer candidates and a target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_Vector(vector<vector<int>> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    for (auto it = ip->begin(); it != ip->end(); it++) {
      int a = *it;
      cout << a << ",";
    }
    cout << endl;
  }
}
// Recursive function to find all possible combinations.
void func(vector<int> candidates, int target, int index, vector<int> path,
          vector<vector<int>> &res) {
  // If target is 0, we get the exact answer.
  if (target == 0) {
    res.push_back(path);
    return;
  }
  // Edge cases
  if (index == candidates.size() || target < 0) {
    return;
  }
  if (candidates[index] <= target) {
    // Push the value to the list
    path.push_back(candidates[index]);
    // Subtract from original target and make a recursive call
    func(candidates, target - candidates[index], index, path, res);
    // Remove number from list (backtracking to remove additional numbers)
    path.pop_back();
  }
  // Move to the next index and continue the process through recursion.
  func(candidates, target, index + 1, path, res);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<int> path;
  vector<vector<int>> ans;
  // sort array
  sort(candidates.begin(), candidates.end());
  // remove duplicates
  candidates.erase(unique(candidates.begin(), candidates.end()),
                   candidates.end());
  // call the recursive function.
  func(candidates, target, 0, path, ans);

  return ans;
}

int main() {
  vector<int> candidates = {2, 7, 6, 3, 5, 1};
  int target = 9;
  vector<vector<int>> ans = combinationSum(candidates, target);
  print_Vector(ans);
}