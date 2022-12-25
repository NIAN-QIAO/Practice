#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
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
                if (que.empty())
                    node->next = NULL;
                else
                {
                    if (size != 0)
                        node->next = que.front();
                    else
                        node->next = NULL;
                }
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }
        }
        return root;
    }
};