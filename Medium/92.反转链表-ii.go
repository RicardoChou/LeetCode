/*
 * @lc app=leetcode.cn id=92 lang=golang
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 1.pre始终指向第一个待反转节点的前置节点
// 2.cur始终指向第一个待反转节点
// 3.next指向cur节点的下一个节点
//  扫描的同时进行反转，分三步：
// 1.cur的下一个节点指向next的下一个节点
// 2.把next的下一个节点指向pre的下一个节点
// 3.把pre的下一个节点指向next

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	// 用一个虚拟的头节点统一操作
	dummyNode := &ListNode{Val: -1}
	dummyNode.Next = head
	pre := dummyNode
	// 找到第一个待反转的节点，pre指向其前置节点
	for i := 0; i < left-1; i++ {
		pre = pre.Next
	}
	cur := pre.Next
	//  扫描的同时进行反转，分三步：
	// 1.cur的下一个节点指向next的下一个节点
	// 2.把next的下一个节点指向pre的下一个节点
	// 3.把pre的下一个节点指向next
	for i := 0; i < right-left; i++ {
		next := cur.Next
		cur.Next = next.Next
		next.Next = pre.Next
		pre.Next = next
	}
	return dummyNode.Next
}

// @lc code=end

