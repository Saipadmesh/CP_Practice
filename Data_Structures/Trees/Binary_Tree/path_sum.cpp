// Given the root of a binary tree and an integer targetSum, return true if the
// tree has a root-to-leaf path such that adding up all the values along the
// path equals targetSum.

#include <iostream>
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
// Use a recursive function to traverse through tree and decrement the target
// with node val. If a node is a leaf node and target is 0, path exists.
bool pathSum(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return false;
  }
  if (targetSum - root->val == 0 && root->left == nullptr &&
      root->right == nullptr) {
    return true;
  }
  return pathSum(root->left, targetSum - root->val) ||
         pathSum(root->right, targetSum - root->val);
}

int main() {
  vector<int> arr = {-2, 0, -3};
  TreeNode *root = buildTree(arr, 0, root);
  cout << pathSum(root, -5) << endl;
}