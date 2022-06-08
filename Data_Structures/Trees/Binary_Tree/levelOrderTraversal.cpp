#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  // Represents node of a tree
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<TreeNode *> queue;
  vector<vector<int>> ans;
  if (!root)
  {
    return ans;
  }
  // ans.push_back({root->val});
  queue.push_back(root);
  vector<int> temp;
  while (queue.size() != 0)
  {
    int n = queue.size();
    for (int i = 0; i < n; i++)
    {

      TreeNode *curr = queue[0];
      queue.erase(queue.begin());
      if (curr->left)
      {
        queue.push_back(curr->left);
      }
      if (curr->right)
      {
        queue.push_back(curr->right);
      }
      temp.push_back(curr->val);
    }
    if (temp.size())
    {
      ans.push_back(temp);
      temp.clear();
    }
  }
  return ans;
}