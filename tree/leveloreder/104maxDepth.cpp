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
    int result = INT_MIN;
    int maxDepth1(TreeNode *root) // 最优解答
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    void traversal(TreeNode *node, int &depth)
    {
        depth++;
        if (node == NULL)
        {
            depth--;
            return;
        }
        else
        {
            traversal(node->left, depth);
            traversal(node->right, depth);
            if (depth > result)
            {
                result = depth;
            }
            depth--;
        }
    }
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        traversal(root, depth);
        if (root == NULL)
            result = 0;
        return result;
    }
};