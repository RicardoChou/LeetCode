/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    // 用于翻转每k个一组的辅助函数
    pair<ListNode *, ListNode *> subReverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre = tail->next;
        ListNode *p = head;
        while (pre != tail)
        {
            ListNode *q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        return {tail, head};
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 创建一个虚拟的头节点用来统一运算
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        // 虚头节点作为最初的pre
        ListNode *pre = dummy;
        while (head)
        {
            ListNode *tail = pre;
            // 判断剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (!tail)
                {
                    return dummy->next;
                }
            }
            ListNode *q = tail->next;
            pair<ListNode *, ListNode *> result = subReverse(head, tail);
            // 重新设置head和tail
            head = result.first;
            tail = result.second;
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = q;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};
// @lc code=end
