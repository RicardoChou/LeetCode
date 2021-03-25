/*
 * @lc app=leetcode.cn id=82 lang=golang
 *
 * [82] 删除排序链表中的重复元素 II
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
	// 虚节点来统一操作
	dummyNode := &ListNode{Val: -1}
	dummyNode.Next = head
	// cur指向前一个没有重复的节点
	cur := dummyNode
	// 循环
	for cur.Next != nil && cur.Next.Next != nil {
		// 如果后续出现重复节点
		if cur.Next.Val == cur.Next.Next.Val {
			// 循环删除每个重复的节点
			temp := cur.Next.Val
			for cur.Next != nil && cur.Next.Val == temp {
				cur.Next = cur.Next.Next
			}
			// 更新前一个没有重复的节点
		} else {
			cur = cur.Next
		}
	}
	return dummyNode.Next
}

// @lc code=end

