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
// 递归三部曲
/*1.确定递归函数的参数和返回值
2.确定终止条件
3.确定单层递归的逻辑
*/
class Solution
{
public:
    bool dfs(TreeNode *left, TreeNode *right)
    { // 确定终止条件
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL || right == NULL)
            return false;
        else if (left->val != right->val)
            return false;
        // 本层次操作
        /*比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。
        比较内测是否对称，传入左节点的右孩子，右节点的左孩子。
        如果左右都对称就返回true ，有一侧不对称就返回false 。*/
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return false;
        return dfs(root->left, root->right);
    }
};