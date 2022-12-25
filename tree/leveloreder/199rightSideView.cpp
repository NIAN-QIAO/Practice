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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> tmp;
        vector<int> result;
        queue<TreeNode *> que;
        TreeNode *node;
        int location;
        int size;
        if (root != NULL)
            que.push(root);
        else
            return result;
        while (!que.empty())
        {
            size = que.size();
            while (size)
            {
                node = que.front();
                que.pop();
                tmp.push_back(node->val);
                size--;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            location = tmp.size() - 1;
            result.push_back(tmp[location]);
        }
        return result;
    }
};