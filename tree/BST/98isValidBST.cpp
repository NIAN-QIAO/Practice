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
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        bool left = isValidBST(root->left);
        if (maxVal < root->val)
            maxVal = root->val;
        else
            return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

// 纯纯的错误，左子树所有节点都小于，右子树所有节点都大于
// 感觉所有代码写的都不是很简洁
//  class Solution
//  {
//  public:
//      int count = 1;
//      bool isValidBST(TreeNode *root)
//      {
//          bool result = true;
//          if (root != NULL && root->left == NULL && root->right == NULL)
//              return true;
//          if (root != NULL && root->left != NULL)
//          {
//              if (root->val > root->left->val)
//                  result = true;
//              else
//                  return false;
//          }
//          if (root != NULL && root->right != NULL)
//          {
//              if (root->val < root->right->val)
//                  result = true;
//              else
//                  return false;
//          }
//          // cout << count++ << "  root->val:" << root->val << "root->left->val:" << root->left->val << "root->right->val:" << root->right->val << "result:" << result << endl;
//          bool result1 = true, result2 = true;
//          if (result)
//          {
//              if (root->left != NULL)
//                  result1 = isValidBST(root->left);
//              if (root->right != NULL)
//                  result2 = isValidBST(root->right);
//              return result1 && result2;
//          }
//          return result;
//      }
//  };