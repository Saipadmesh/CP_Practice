#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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
string serialize(TreeNode *root)
{
    string data = "";
    if (root == nullptr)
    {
        return data;
    }
    queue<TreeNode *> q;
    TreeNode *curr;
    q.push(root);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (curr == nullptr)
        {
            data += "n,";
            continue;
        }

        q.push(curr->left);
        q.push(curr->right);
        data += to_string(curr->val) + ",";
    }
    return data;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    stringstream ss(data);
    string val;
    getline(ss, val, ',');
    TreeNode *root = new TreeNode(stoi(val));

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        getline(ss, val, ',');
        if (val != "n")
        {
            temp->left = new TreeNode(stoi(val));
            q.push(temp->left);
        }
        getline(ss, val, ',');
        if (val != "n")
        {
            temp->right = new TreeNode(stoi(val));
            q.push(temp->right);
        }
    }

    return root;
}