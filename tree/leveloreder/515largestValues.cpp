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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        int max = INT_MIN;
        int size;
        queue<TreeNode *> que;
        TreeNode *node;
        if (root != NULL)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            size = que.size();
            while (size--)
            {
                node = que.front();
                que.pop();
                if (node->val > max)
                    max = node->val;
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }
            result.push_back(max);
            max = INT_MIN;
        }
        return result;
    }
};