/*
 * @lc app=leetcode.cn id=61 lang=golang
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	// 特殊情况
	if k == 0 || head == nil || head.Next == nil {
		return head
	}
	temp, length := head, 1
	// 求出链表的长度
	for temp.Next != nil {
		length++
		temp = temp.Next
	}
	// 防止循环重复
	k = length - k%length
	// 特殊情况
	if k == length {
		return head
	}
	// 第一遍遍历的时候就将尾节点的Next指针指向head
	temp.Next = head
	// 找到新的头节点
	for k > 0 {
		temp = temp.Next
		k--
	}
	// 新的头节点
	res := temp.Next
	// 新尾节点的Next置空
	temp.Next = nil
	return res
}

// @lc code=end

