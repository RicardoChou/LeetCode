/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        //链表为空或者只有一个节点，那不管怎样翻转都不变
        if (!head || !head->next)
            return head;
        //扫描一遍链表，得到链表长度的同时得到尾节点
        ListNode *tail = head;
        int length = 1;
        //得到链表长度的同时得到尾节点
        while (tail->next != NULL)
        {
            length++;
            tail = tail->next;
        }
        //k有可能大于链表长度，这时候就等于将链表翻转了几个重复
        //所以求k%length，得到链表实际上需要移动到的位置
        k = k % length;
        //k等于0则不需要旋转
        if (k == 0)
            return head;
        ListNode *newHead = head;
        ListNode *pre = head;
        //这个k实际上是从后往前数第几个节点，所以从前往后数的话，作为新head的节点是第length-k+1个节点
        //然后就是简单的链表连接，注意不断链即可
        for (int i = 0; i < length - k; i++)
        {
            pre = newHead;
            newHead = newHead->next;
        }
        //新链接尾节点的next要置空
        pre->next = NULL;
        //原链表的尾节点的next指向原head节点
        tail->next = head;
        return newHead;
    }
};
// @lc code=end
