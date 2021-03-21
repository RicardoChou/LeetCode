/*
 * @lc app=leetcode.cn id=142 lang=golang
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//  快慢双指针法
func detectCycle(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil {
		// 慢指针每次向后一个节点
		slow = slow.Next
		// 无环
		if fast.Next == nil {
			return nil
		}
		// 快指针每次向后两个节点
		fast = fast.Next.Next
		// 有环的情况下，让快指针重置为头节点，与慢指针同时每次向后一个节点
		// 第二次相遇的节点即是环的入口
		if fast == slow {
			fast := head
			for fast != slow {
				fast = fast.Next
				slow = slow.Next
			}
			return fast
		}
	}
	return nil
}

// @lc code=end

