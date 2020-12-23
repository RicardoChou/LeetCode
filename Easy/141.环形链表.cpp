/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    //双指针
    bool hasCycle(ListNode *head)
    {
        //快慢双指针
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next)
        {
            //慢指针每次循环向后一位
            slow = slow->next;
            //快指针每次循环向后两位
            fast = fast->next;
            fast = fast->next;
            //快指针遇到慢指针则说明有环路
            if (slow == fast)
                return true;
        }
        //遍历到最后则说明无环路
        return false;
    }
};
// @lc code=end
