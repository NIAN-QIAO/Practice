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
}; /*递归三步走
 1.确定参数，返回值
 2.终止条件*/
class Solution
{
public:
    int height(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right); // 每个节点都是平衡二叉树
    }
};