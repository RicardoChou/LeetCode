/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        //特殊情况
        if (head == NULL)
            return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        //找到m所在的位置
        while (m > 1)
        {
            pre = cur;
            cur = cur->next;
            m--;
            //n也要同时减一
            n--;
        }
        //这两个指针是用来标记需要反转的那一小段链表的头和尾的
        //这里采用的方法是全部进行反转，到最后再对这一小段的头和尾进行特殊处理
        ListNode *prev = pre;
        ListNode *tail = cur;
        //用于标记cur的下一个节点，防止断链
        ListNode *r = NULL;
        while (n > 0)
        {
            //防止断链
            r = cur->next;
            //进行反转
            cur->next = pre;
            pre = cur;
            cur = r;
            n--;
        }
        //对需要反转的那一小段链表的头和尾节点进行特殊的处理
        if (prev != NULL)
            prev->next = pre;
        else
            head = pre;
        tail->next = cur;
        return head;
    }
};
// @lc code=end
