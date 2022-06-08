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

// Helper function to build tree
TreeNode *buildTree(const vector<int> treeVals, int pos, TreeNode *curr)
{
    if (pos < treeVals.size())
    {
        TreeNode *temp = new TreeNode(treeVals[pos]);
        curr = temp;
        curr->left = buildTree(treeVals, 2 * pos + 1, curr->left);
        curr->right = buildTree(treeVals, 2 * pos + 2, curr->right);
    }

    return curr;
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = 1 + maxDepth(root->left);
    int rightHeight = 1 + maxDepth(root->right);
    return max(leftHeight, rightHeight);
}
