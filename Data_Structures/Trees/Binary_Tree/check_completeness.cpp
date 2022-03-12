// Given the root of a binary tree, determine if it is a complete binary tree.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Represents node of a tree
struct TreeNode {
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

bool checkCompleteness(TreeNode *root, vector<int> prevNull) { return true; }

bool isCompleteTree(TreeNode *root) {
  queue<TreeNode *> nodeQ;
  bool checkPrev = true;
  nodeQ.push(root);
  while (!nodeQ.empty()) {
    TreeNode *curr = nodeQ.front();
    nodeQ.pop();
    if (curr == nullptr || curr->val == 0) {
      checkPrev = false;
      continue;
    }
    if (!checkPrev && curr) {
      return false;
    }

    nodeQ.push(curr->left);
    nodeQ.push(curr->right);
  }
  return true;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 0, 7};
  TreeNode *root = buildTree(arr, 0, root);
  bool ans = isCompleteTree(root);
  cout << ans << endl;
}