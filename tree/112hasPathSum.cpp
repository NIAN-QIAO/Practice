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
    bool result = false;
    int sum = 0;
    int target;
    void dfs(TreeNode *node)
    {
        sum = sum + node->val;
        if (node->left)
            dfs(node->left);
        if (node->right)
            dfs(node->right);
        if (node->left == NULL && node->right == NULL)
        {
            // cout << sum;
            if (sum == target)
                result = true;
        }
        sum = sum - node->val;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        target = targetSum;
        dfs(root);
        return result;
    }
};