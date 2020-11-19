/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        //特殊情况
        if (!head || !head->next)
            return head;
        //新建一个空的头节点用于统一运算（不然就要特殊考虑第一个节点就应该删除的情况）
        ListNode *dummyhead = new ListNode(INT_MAX);
        dummyhead->next = head;
        ListNode *pre = dummyhead;
        while (pre && pre->next)
        {
            ListNode *cur = pre->next;
            // 如果cur到最后一位了或者当前cur所指元素没有重复值
            if (!cur->next || cur->next->val != cur->val)
                pre = cur;
            else
            {
                // 将cur定位到一串重复元素的最后一位
                while (cur->next && cur->next->val == cur->val)
                    cur = cur->next;
                // pre->next跳过中间所有的重复元素
                pre->next = cur->next;
            }
        }
        return dummyhead->next;
    }
};
// @lc code=end
