/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
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
    ListNode *partition(ListNode *head, int x)
    {
        //相当于将链表拆分成两个，再重新链接
        //一个是小于x的链表，一个是大于x的链表
        //head1和head2是哑节点
        ListNode *head1 = new ListNode(-1);
        ListNode *head2 = new ListNode(-1);
        ListNode *p = head1;
        ListNode *q = head2;
        while (head)
        {
            if (head->val < x)
            {
                p->next = head;
                p = head;
            }
            else
            {
                q->next = head;
                q = head;
            }
            //要记得将head后移才行
            head = head->next;
        }
        //最后节点的next域要置空
        q->next = NULL;
        p->next = head2->next;
        return head1->next;
    }
};
// @lc code=end
