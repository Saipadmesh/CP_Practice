#include <iostream>
#include <vector>
#include <climits>

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

bool isValidBST(TreeNode *root, long min = LONG_MIN, long max = LONG_MAX)
{
    if (!root)
    {
        return true;
    }
    if (root->val >= max || root->val <= min)
    {
        return false;
    }

    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}