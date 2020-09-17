/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //新建一个链表，初始结点数设为0
        ListNode temp_head(0);
        //游标结点
        ListNode *ptr = &temp_head;
        //两个链表都不为空的时候才需要继续
        //如果任意一个到末尾了，就可以退出循环了
        while (l1 && l2)
        {
            //选择结点值较小的姐点作为新链表的结点
            //同时将较小值得旧链表进行后移
            if (l1->val <= l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            //新链表的游标结点后移
            ptr = ptr->next;
        }
        //将两个链表中较长的那个链表剩余结点全部作为新链表的尾部
        if (l1)
            ptr->next = l1;
        if (l2)
            ptr->next = l2;

        return temp_head.next;
    }
};
// @lc code=end
