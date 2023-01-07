#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void dfs(TreeNode *node, vector<string> &result, string tmp)
    {
        tmp = tmp + "->" + to_string(node->val);
        if (node->left == NULL && node->right == NULL)
        {
            result.push_back(tmp);
            return;
        }
        if (node->left != NULL)
        {
            dfs(node->left, result, tmp);
        }
        if (node->right != NULL)
        {
            dfs(node->right, result, tmp);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string tmp = to_string(root->val);
        if (root == NULL)
            return {};
        if (root->left != NULL)
        {
            dfs(root->left, result, tmp);
        }
        if (root->right != NULL)
        {
            dfs(root->right, result, tmp);
        }
        if (root->left == NULL && root->right == NULL)
        {
            result.push_back(tmp);
        }
        return result;
    }
};