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
    TreeNode *invertTree(TreeNode *root) // 层次遍历好像好用一点
    {
        TreeNode *tmp, *temp;
        int size;
        queue<TreeNode *> que;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            size = que.size();
            while (size--)
            {
                tmp = que.front();
                que.pop();
                temp = tmp->left;
                tmp->left = tmp->right;
                tmp->right = temp;
                if (tmp->left != NULL)
                {
                    que.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    que.push(tmp->right);
                }
            }
        }
        return root;
    }
};