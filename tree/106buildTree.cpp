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
private:
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return NULL;
        // 后序遍历的最后一个元素为中间节点
        int rootvalue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootvalue);
        // 叶子节点
        if (postorder.size() == 1)
            return root;
        int delimiterIndex;
        // 中序遍历的切割点
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootvalue)
                break;
        }

        // 切割中序数组
        //[0,delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //[delimiterIndex+1,end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        // 舍弃后序遍历数组的最后一个元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        //[0,leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        //[leftInorder.size(),end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }

public: // inorder是中序遍历，postorder是后序遍历
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
};