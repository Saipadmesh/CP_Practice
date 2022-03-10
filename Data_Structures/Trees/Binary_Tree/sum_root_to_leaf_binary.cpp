// You are given the root of a binary tree where each node has a value 0 or 1.
// Each root-to-leaf path represents a binary number starting with the most
// significant bit.
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  // Represents node of a tree
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *buildTree(const vector<int> treeVals, int pos, TreeNode *curr) {
  // Helper function to build tree
  if (pos < treeVals.size()) {
    TreeNode *temp = new TreeNode(treeVals[pos]);
    curr = temp;
    curr->left = buildTree(treeVals, 2 * pos + 1, curr->left);
    curr->right = buildTree(treeVals, 2 * pos + 2, curr->right);
  }

  return curr;
}

void print_Vector(vector<int> ans) {
  // Helper function to print a vector
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    int a = *ip;
    cout << a << ",";
  }
  cout << endl;
}

// To convert a binary number to decimal while traversing, left shift number by
// 1, and add the current number using |.
int pathSum(TreeNode *root, int total) {
  if (root->left == nullptr && root->right == nullptr) {
    return (total << 1 | root->val);
  }
  if (root == nullptr) {
    return 0;
  }
  // nums.push_back(root->val);
  int current = root->val;
  int temp = 0;
  if (root->left) {
    temp += pathSum(root->left, (total << 1 | current));
  }
  if (root->right) {
    temp += pathSum(root->right, (total << 1 | current));
  }
  return temp;
}

int main() {
  vector<int> arr = {1, 0, 1, 0, 1, 0, 1};
  TreeNode *root = buildTree(arr, 0, root);
  int ans = pathSum(root, 0);
  cout << ans << endl;
}
