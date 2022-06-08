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
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}