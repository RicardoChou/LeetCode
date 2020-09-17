/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        //空链表特殊考虑
        if (head == NULL)
            return head;
        //pre是前置节点，p是游标节点
        ListNode *pre = head, *p = head->next;
        //循环直至游标结点为空也就是移动到末尾
        while (p != NULL)
        {
            //如果前置节点的值和游标节点的值不同，则将前置节点的next指针指向游标结点
            if (pre->val != p->val)
            {
                //将前置节点的next指针指向游标结点
                pre->next = p;
                //同时前置指针移动到游标节点
                pre = p;
                //游标结点继续后移进行扫描
                p = p->next;
            }
            //如果前置节点的值和游标节点的值相同，则游标节点后移继续扫描
            else
                p = p->next;
        }
        //最后需要将前置节点的next指针赋为NULL
        //这样可以保证最后一段相同的数字的节点也能被删除
        pre->next = NULL;
        return head;
    }
};
// @lc code=end
