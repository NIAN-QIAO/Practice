#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#include <math.h>
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
    int result = INT_MAX;
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
            if (node->left == NULL && node->right == NULL) // 左右节点全部为空，走到尽头才开始判断
            {
                if (depth < result)
                    result = depth;
            }
            depth--;
        }
    }
    int minDepth(TreeNode *root)
    {
        int depth = 0;
        traversal(root, depth);
        if (root == NULL)
            result = 0;
        return result;
    }
};