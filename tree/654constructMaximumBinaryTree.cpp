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
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return NULL;
        int max = INT_MIN, maxIndex = INT_MIN;
        for (int index = left; index < right; index++)
        {
            if (nums[index] > max)
            {
                maxIndex = index;  // 最大值
                max = nums[index]; // 最大下标
            }
        }
        TreeNode *root = new TreeNode(max);
        root->left = traversal(nums, left, maxIndex);
        // cout << left << "  " << maxIndex - 1;
        root->right = traversal(nums, maxIndex + 1, right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return traversal(nums, 0, nums.size());
    }
};