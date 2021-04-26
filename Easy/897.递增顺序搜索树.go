/*
 * @lc app=leetcode.cn id=897 lang=golang
 *
 * [897] 递增顺序搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 先中序遍历二叉树将结果保存到一个列表中
// 然后根据列表中的节点值，创建等价的只含有右节点的二叉搜索树，其过程等价于根据节点值创建一个链表
func increasingBST(root *TreeNode) *TreeNode {
	vals := []int{}
	var inorder func(*TreeNode)
	inorder = func(node *TreeNode) {
		if node != nil {
			inorder(node.Left)
			vals = append(vals, node.Val)
			inorder(node.Right)
		}
	}
	inorder(root)

	dummyNode := &TreeNode{}
	curNode := dummyNode
	for _, val := range vals {
		curNode.Right = &TreeNode{Val: val}
		curNode = curNode.Right
	}
	return dummyNode.Right
}

// @lc code=end

