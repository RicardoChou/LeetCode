/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
    ListNode *swapPairs(ListNode *head)
    {
        //建立一个dummy结点用来作为头结点来简化操作
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *p = dummy->next, *q;
        //交换节点的过程中要保证不能断链
        while (p && p->next)
        {
            q = p->next;
            pre->next = q;
            p->next = q->next;
            q->next = p;
            pre = p;
            p = p->next;
        }
        /*返回的时候要注意返回dummy->next而不是head，
          因为head在交换过程中始终指向未交换前的第一个结点，若是最后返回head，
          会漏掉结束后的第一个结点，
          而dummy->next始终指向第一个结点
        */
        return dummy->next;
    }
};
// @lc code=end
