#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<int> row;
        vector<vector<int>> result;
        queue<TreeNode *> que;
        TreeNode *node;
        int size;
        if (root != NULL)
        {
            que.push(root);
        }
        else
            return result;
        while (!que.empty())
        {
            size = que.size();
            // 清除当前层次中的所有数数据
            while (size)
            {
                node = que.front();
                row.push_back(node->val);
                que.pop();
                size--;
                // 添加下一层
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }
            result.push_back(row);
            row.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};