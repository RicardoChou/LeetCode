/*
 * @lc app=leetcode.cn id=1893 lang=golang
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start
// 差分思想
func isCovered(ranges [][]int, left, right int) bool {
	diff := [52]int{} // 差分数组
	for _, v := range ranges {
		diff[v[0]]++
		diff[v[1]+1]--
	}
	cnt := 0 // 前缀和
	for i := 1; i <= 50; i++ {
		cnt += diff[i]
		if cnt <= 0 && left <= i && i <= right {
			return false
		}
	}
	return true
}

// @lc code=end

