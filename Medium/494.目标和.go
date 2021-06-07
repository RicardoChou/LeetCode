/*
 * @lc app=leetcode.cn id=494 lang=golang
 *
 * [494] 目标和
 */

// @lc code=start
// 回溯：实际上就是将每个数字尝试用加或者减的可能结果比较一下而已
// 初始时和是0
func findTargetSumWays(nums []int, target int) int {
	counter := 0
	var backtrack func(int, int)
	backtrack = func(index, sum int) {
		if index == len(nums) {
			if sum == target {
				counter++
			}
			return
		}
		backtrack(index+1, sum+nums[index])
		backtrack(index+1, sum-nums[index])
	}
	backtrack(0, 0)
	return counter
}

// @lc code=end

