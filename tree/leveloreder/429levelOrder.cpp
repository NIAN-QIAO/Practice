#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;
    Node() {}
    Node(int _val)
    {
        val = _val;
    }
    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<int> tmp;
        vector<vector<int>> result;
        queue<Node *> que;
        Node *node;
        int size;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            size = que.size();
            while (size--)
            {
                node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->children.size() != 0) // 判断子节点是否为空
                {
                    for (int i = 0; i < node->children.size(); i++)
                    {
                        que.push(node->children[i]);
                    }
                }
            }
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};