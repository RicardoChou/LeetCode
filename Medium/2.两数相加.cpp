/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    //题目是逆序存储，也就是位数小的在链表的前面
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        //*l3是新链表的头指针
        ListNode *l3 = new ListNode(0);
        //*cur是游标指针
        ListNode *p = l1, *q = l2, *cur = l3;
        //变量carry用来表示进位
        int x1, x2, sum, carry = 0;
        while (p || q)
        {
            //如果节点不为空就把结点值赋给x1与x2，为空则直接赋为0
            x1 = (p != NULL) ? p->val : 0;
            x2 = (q != NULL) ? q->val : 0;
            //同等位置的节点值与进位相加
            sum = x1 + x2 + carry;
            //新建节点，节点值小于10的
            cur->next = new ListNode(sum % 10);
            //求进位是0还是1
            carry = sum / 10;
            //油表指针后移
            cur = cur->next;
            //l1与l2的游标指针同时后移
            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
        }
        //如果遍历完两个链表所有节点之后进位为1
        //则需要在链表最后加上一个新节点赋值为1
        if (carry == 1)
        {
            cur->next = new ListNode(1);
        }
        //l3头指针指向的是头节点，应该返回它的next节点
        return l3->next;
    }
};
// @lc code=end
