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
    vector<double> averageOfLevels(TreeNode *root)
    {
        // vector<int> tmp;
        vector<double> result;
        queue<TreeNode *> que;
        TreeNode *node;
        double num = 0;
        int location;
        int size, count;
        if (root != NULL)
            que.push(root);
        else
            return result;
        while (!que.empty())
        {
            num = 0;
            count = size = que.size();
            while (size)
            {
                node = que.front();
                que.pop();
                // tmp.push_back(node->val);
                num = num + double(node->val);
                size--;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }

            result.push_back(num / count);
        }
        return result;
    }
};