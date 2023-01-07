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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        bool state = false;
        TreeNode *node;
        int size;
        int result; // 记录每层的最左边
        while (!que.empty())
        {
            size = que.size();
            state = false;
            result = que.front()->val;
            while (size--)
            {
                node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                    state = true;
                }
                if (node->right)
                {
                    que.push(node->right);
                    state = true;
                }
            }
            if (!state)
            {
                return result;
            }
        }
        return 0;
    }
};