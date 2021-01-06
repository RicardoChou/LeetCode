/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    // 合并两个有序链表作为基函数
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if ((!a) || (!b))
            return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
    // 分治法将链表进行两两合并
    // 比如共有8个数组，那第一轮分成四组，合并完变成4个数组
    // 第二轮就分成两组
    // 第三轮就合并成一组
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end
