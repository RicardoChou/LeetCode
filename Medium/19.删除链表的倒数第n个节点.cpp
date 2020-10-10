/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    //双指针，前指针比后指针先移动n个节点
    //这样前指针移动至最后一个节点之后
    //后指针就是倒数第n个节点
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        //前指针先移动n个节点
        while (n--)
            fast = fast->next;
        //如果前指针已经到达最后一个节点，说明要删除的第一个节点
        //这样只需要返回第二个节点即可
        //（因为题设说明了n是有效的数字）
        if (!fast)
            return head->next;
        ListNode *slow = head;
        //前指针和后指针同时移动直至前指针移动至最后一个节点
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //删除倒数第n个节点
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end
