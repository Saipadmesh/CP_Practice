#include <iostream>
#include <vector>
#include <climits>
#include <stack>

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

int kthSmallest(TreeNode *root, int &k)
{
    stack<TreeNode *> s;
    TreeNode *temp = root;
    s.push(root);
    while (true)
    {
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        if (--k == 0)
        {
            return temp->val;
        }
        temp = temp->right;
    }
}