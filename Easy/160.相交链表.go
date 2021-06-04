/*
 * @lc app=leetcode.cn id=160 lang=golang
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 用一个哈希表存储headA链表的所有节点
//  然后遍历headB的节点，如果有节点在哈希表中存在，则该节点就是第一个相交节点
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	isExist := map[*ListNode]bool{}
	for temp := headA; temp != nil; temp = temp.Next {
		isExist[temp] = true
	}
	for temp := headB; temp != nil; temp = temp.Next {
		if isExist[temp] == true {
			return temp
		}
	}
	return nil
}

// @lc code=end

