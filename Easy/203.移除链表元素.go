/*
 * @lc app=leetcode.cn id=203 lang=golang
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//  用一个头节点来统一操作
func removeElements(head *ListNode, val int) *ListNode {
	dummyNode := &ListNode{Next: head}
	for tmp := dummyNode; tmp.Next != nil; {
		if tmp.Next.Val == val {
			tmp.Next = tmp.Next.Next
		} else {
			tmp = tmp.Next
		}
	}
	return dummyNode.Next
}

// @lc code=end

