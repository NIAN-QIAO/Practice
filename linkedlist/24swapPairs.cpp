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
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        ListNode *tmp = nullptr;
        ListNode *tmp1 = nullptr;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            tmp = cur->next;
            tmp1 = cur->next->next->next;

            cur->next = cur->next->next;  // 步骤一
            cur->next->next = tmp;        // 步骤二
            cur->next->next->next = tmp1; // 步骤三

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};