/*
 * @lc app=leetcode.cn id=173 lang=golang
 *
 * [173] 二叉搜索树迭代器
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

//  nums：保存递增的切片
// root：根节点
type BSTIterator struct {
	nums []int
	root *TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	nums := make([]int, 0)
	// 得到二叉树中序遍历之后的切片
	inorder(root, &nums)
	return BSTIterator{
		root: root,
		nums: nums,
	}
}

func (this *BSTIterator) Next() int {
	num := this.nums[0]
	this.nums = this.nums[1:]
	return num
}

func (this *BSTIterator) HasNext() bool {
	return len(this.nums) > 0
}

// 中序遍历获取一个递增的数组，通过迭代该数组间接迭代二叉树
func inorder(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	// 先遍历左子树
	inorder(root.Left, nums)
	// 再遍历根节点
	*nums = append(*nums, root.Val)
	// 最后遍历右子树
	inorder(root.Right, nums)
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
// @lc code=end

