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
        //新建一个哑节点用于统一运算（不然就要特殊考虑第一个节点就应该删除的情况）
        ListNode *dummyhead = new ListNode(INT_MAX);
        dummyhead->next = head;
        ListNode *pre = dummyhead;
        ListNode *cur = head;
        while (cur && cur->next)
        {
            //初始化的时pre指向的是哑结点，所以比较逻辑应该是pre的下一个节点和cur的下一个节点
            if (pre->next->val != cur->next->val)
            {
                pre = pre->next;
                cur = cur->next;
            }
            else
            {
                //如果pre、cur指向的节点值相等，就不断移动cur，直到pre、cur指向的值不相等
                while (cur && cur->next && pre->next->val == cur->next->val)
                    cur = cur->next;
                // pre->next跳过中间所有的重复元素
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        return dummyhead->next;
    }
};
// @lc code=end
