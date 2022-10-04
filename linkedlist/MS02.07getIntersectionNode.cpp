/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int countA = 0, countB = 0;
        while (curB != nullptr)
        {
            curB = curB->next;
            countB++;
        }
        while (curA != nullptr)
        {
            curA = curA->next;
            countA++;
        }
        if (countA >= countB)
        {
            return demo(headA, headB, countA - countB);
        }
        else
        {
            return demo(headB, headA, countB - countA);
        }
    }
    ListNode *demo(ListNode *chang, ListNode *duan, int diff)
    {
        for (int i = 1; i <= diff; i++)
        {
            chang = chang->next;
        }
        while (chang != nullptr)
        {
            if (chang == duan)
                return chang;
            else
            {
                chang = chang->next;
                duan = duan->next;
            }
        }
        return nullptr;
    }
};
//尽量不用...->next作为判断条件，防止链表为空