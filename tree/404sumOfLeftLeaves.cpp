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
    int sum = 0;
    void dfs(TreeNode *node, int num)
    {
        if (node == NULL)
            return; //
        if (node->left == NULL && node->right == NULL)
        {
            if (num == 0)
                sum += node->val;
        }
        dfs(node->left, 0);
        dfs(node->right, 1);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        dfs(root->left, 0);
        dfs(root->right, 1);
        return sum;
    }
};