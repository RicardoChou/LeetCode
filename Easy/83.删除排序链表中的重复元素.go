/*
 * @lc app=leetcode.cn id=83 lang=golang
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	dummyNode := &ListNode{Val: -10000}
	dummyNode.Next = head
	pre, p := dummyNode, head
	for p != nil {
		if pre.Val == p.Val {
			p = p.Next
			pre.Next = p
		} else {
			pre = p
			p = p.Next
		}
	}
	return dummyNode.Next
}

// @lc code=end

