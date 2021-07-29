#include <iostream>
#include <vector>
using namespace std;
// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target.

void print_Vector(vector<vector<int>> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    for (auto it = ip->begin(); it != ip->end(); it++) {
      int a = *it;
      cout << a << ",";
    }
    cout << endl;
  }
}

void func(vector<int> candidates, int target, int index, vector<int> path,
          vector<vector<int>> &res) {

  if (target == 0) {
    res.push_back(path);
    return;
  }
  if (index == candidates.size() || target < 0) {
    return;
  }
  if (candidates[index] <= target) {
    path.push_back(candidates[index]);
    func(candidates, target - candidates[index], index, path, res);
    path.pop_back();
  }
  func(candidates, target, index + 1, path, res);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<int> path;
  vector<vector<int>> ans;
  func(candidates, target, 0, path, ans);

  return ans;
}

int main() {
  vector<int> candidates = {2, 7, 6, 3, 5, 1};
  int target = 9;
  vector<vector<int>> ans = combinationSum(candidates, target);
  print_Vector(ans);
}