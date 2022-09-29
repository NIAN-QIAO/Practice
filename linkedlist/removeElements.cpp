#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *virNode = new ListNode(0, head);
    ListNode *curNode = virNode;
    while (curNode->next != NULL)
    {
        if (curNode->next->val == val)
        {
            ListNode *tempNode = curNode->next;
            curNode->next = curNode->next->next;
            delete tempNode;
        }
        else
        {

            curNode = curNode->next;
        }
    }
    head = virNode->next;
    delete virNode;
    return head;
}
int main()
{
}