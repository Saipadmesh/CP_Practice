#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

stack<TreeNode *> s;
set<TreeNode *> set1;
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

  TreeNode *head = NULL;
  int pre_index = 0, in_index = 0;
  int n = preorder.size();
  while (pre_index < n) {
    TreeNode *node = new TreeNode(preorder[pre_index]);
    do {
      if (head == NULL) {
        head = node;
      }
      if (set1.size() > 0) {
        if (set1.find(s.top()) != set1.end()) {
          s.top()->right = node;
          set1.erase(s.top());
          s.pop();
        } else {
          s.top()->left = node;
        }
      }
      s.push(node);
    } while (preorder[pre_index++] != in_index && pre_index < n);

    while (s.size() > 0 && s.top()->val != inorder[in_index] && in_index < n) {
      node = s.top();
      s.pop();
      in_index++;
    }
    if (node != NULL) {
      set1.insert(node);
      s.push(node);
    }
  }

  return head;
}