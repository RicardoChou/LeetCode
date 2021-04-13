/*
 * @lc app=leetcode.cn id=783 lang=golang
 *
 * [783] 二叉搜索树节点最小距离
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
//  二叉搜索树是按照中序遍历有序的，给的例子是升序的，所以只要对二叉搜索树进行中序遍历即可得到升序数组
//  并且差值最小值一定是相邻的两个节点之间出现的
func minDiffInBST(root *TreeNode) int {
	res, pre := math.MaxInt64, -1
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		dfs(node.Left)
		if pre != -1 && node.Val-pre < res {
			res = node.Val - pre
		}
		pre = node.Val
		dfs(node.Right)
	}
	dfs(root)
	return res
}

// @lc code=end

