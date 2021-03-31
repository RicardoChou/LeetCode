/*
 * @lc app=leetcode.cn id=90 lang=golang
 *
 * [90] 子集 II
 */

// @lc code=start
var res [][]int

func subsetsWithDup(nums []int) [][]int {
	res = make([][]int, 0)
	// 排序可以保证重复数字在一起
	sort.Ints(nums)
	dfs([]int{}, nums, 0)
	return res
}

//
func dfs(temp, nums []int, start int) {
	tmp := make([]int, len(temp))
	copy(tmp, temp)
	res = append(res, tmp)
	for i := start; i < len(nums); i++ {
		// 若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		// 数字加入
		temp = append(temp, nums[i])
		// 递归dfs
		dfs(temp, nums, i+1)
		// 若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。
		temp = temp[:len(temp)-1]
	}
}

// @lc code=end

