// Given the root of a binary tree, return the sum of values of its deepest
// leaves.
#include <algorithm>
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

// Helper function to build tree
TreeNode *buildTree(const vector<int> treeVals, int pos, TreeNode *curr) {
  if (pos < treeVals.size()) {
    TreeNode *temp = new TreeNode(treeVals[pos]);
    curr = temp;
    curr->left = buildTree(treeVals, 2 * pos + 1, curr->left);
    curr->right = buildTree(treeVals, 2 * pos + 2, curr->right);
  }

  return curr;
}

// Function to get the height of the tree
int getHeight(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int leftSum = getHeight(root->left);
  int rightSum = getHeight(root->right);
  return 1 + max(leftSum, rightSum);
}

// Use a recursive function to check height and return value of the deepest
// leaves
int getSum(TreeNode *root, int height, int currHeight) {
  if (currHeight == height && root && root->left == nullptr &&
      root->right == nullptr) {
    return root->val;
  }
  if (root == nullptr || currHeight >= height) {
    return 0;
  }

  return getSum(root->left, height, currHeight + 1) +
         getSum(root->right, height, currHeight + 1);
}

int deepestLeavesSum(TreeNode *root) {
  int height = getHeight(root);
  return getSum(root, height, 1);
}

int main() {
  vector<int> arr = {6, 7, 8, 2, 7, 1, 3, 9, 0, 1, 4, 0, 0, 0, 5};
  TreeNode *root = buildTree(arr, 0, root);
  int ans = deepestLeavesSum(root);
  cout << ans << endl;
  // 6, 7, 8, 2, 7, 1, 3, 9, 0, 1, 4, 0, 0, 0, 5
  // 1,2,3,4,5,0,6,7,0,0,0,0,8
}