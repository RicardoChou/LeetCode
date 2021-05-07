/*
 * @lc app=leetcode.cn id=1486 lang=golang
 *
 * [1486] 数组异或操作
 */

// @lc code=start
func xorOperation(n int, start int) int {
	temp := start
	for i := 1; i < n; i++ {
		temp = temp ^ (start + 2*i)
	}
	return temp
}

// @lc code=end

