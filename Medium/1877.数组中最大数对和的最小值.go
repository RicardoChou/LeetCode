/*
 * @lc app=leetcode.cn id=1877 lang=golang
 *
 * [1877] 数组中最大数对和的最小值
 */

// @lc code=start
// 排序之后用贪心，因为排序后最大的数肯定只能和最小的数组成一个数对才能有机会成为最小的和
func minPairSum(nums []int) int {
	sort.Ints(nums)
	var res int
	for i, j := 0, len(nums)-1; i < j; {
		res = max(res, nums[i]+nums[j])
		i++
		j--
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

