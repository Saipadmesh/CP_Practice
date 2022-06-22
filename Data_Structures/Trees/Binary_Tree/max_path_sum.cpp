#include <climits>
#include <iostream>
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
int maxPathSum(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        return root->val;
    }
    int ans = INT_MIN;
    maxPathSumRecursive(root, ans);
    return ans;
}

int maxPathSumRecursive(TreeNode *root, int &maxSum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = max(maxPathSumRecursive(root->left, maxSum), 0), r = max(maxPathSumRecursive(root->right, maxSum), 0);

    maxSum = max(maxSum, l + r + root->val);

    return max(root->val + l, root->val + r);
}