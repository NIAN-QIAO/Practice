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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *node = root;
        while (node != NULL && node->val != val) // 很有意思的问题，leetcode的报错，对链表的使用要求非常的严格，确保指针指向节点不为空。
        {
            if (node->val > val)
                node = node->left;
            else if (node->val < val)
                node = node->right;
        }
        return node;
    }
    TreeNode *searchBST1(TreeNode *root, int val)
    {
        if (root == NULL || root->val == val)
            return root;
        TreeNode *node = NULL;
        if (root->val > val)
            node = searchBST1(root->left, val);
        if (root->val < val)
            node = searchBST1(root->right, val);
        return node;
    }
};