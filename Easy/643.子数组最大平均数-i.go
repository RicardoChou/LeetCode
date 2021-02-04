/*
 * @lc app=leetcode.cn id=643 lang=golang
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
package main

// 求最大平均值本质上就是求最大和
func findMaxAverage(nums []int, k int) float64 {
	sum := 0
	// 前k个数的和
	for _, v := range nums[:k] {
		sum += v
	}
	maxSum := sum
	for i := k; i < len(nums); i++ {
		// 窗口每移动一位，就把左边界的数去掉，再加上右边界新加入的数
		sum = sum - nums[i-k] + nums[i]
		// 每次窗口移动都更新最大和
		maxSum = max(maxSum, sum)
	}
	return float64(maxSum) / float64(k)
}

// 辅助函数求最大和
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
