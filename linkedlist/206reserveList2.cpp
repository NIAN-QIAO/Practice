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
    ListNode *reserve(ListNode *pre, ListNode *cur)
    {
        ListNode *tmp;
        if (cur == nullptr)
            return pre;
        tmp = cur->next;
        cur->next = pre;
        // pre = cur;
        // cur = tmp;
        reserve(cur, tmp);
    }
    ListNode *reverseList(ListNode *head)
    {
        return reserve(nullptr, head);
    }

    /*private:
        ListNode *dummyHead = new ListNode(0, head);*/
};