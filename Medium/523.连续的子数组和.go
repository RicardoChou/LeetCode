/*
 * @lc app=leetcode.cn id=523 lang=golang
 *
 * [523] 连续的子数组和
 */

// @lc code=start
// 前缀和记录从0开始到当前数的和
// 如果两个前缀和的差是k的倍数，那么这两个前缀和除以k的余数是相同的（同余定理）
func checkSubarraySum(nums []int, k int) bool {
	size := len(nums)
	if size < 2 {
		return false
	}
	mp := map[int]int{0: -1}
	remainder := 0
	for i, num := range nums {
		remainder = (remainder + num) % k
		if previndex, ok := mp[remainder]; ok {
			if i-previndex >= 2 {
				return true
			}
		} else {
			mp[remainder] = i
		}
	}
	return false
}

// @lc code=end

