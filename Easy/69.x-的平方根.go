/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] x 的平方根
 */

// @lc code=start
func mySqrt(x int) int {
	if x == 0 {
		return 0
	}
	for i := 1; i < x; i++ {
		if i*i <= x && (i+1)*(i+1) > x {
			return i
		}
	}
	return x
}

// @lc code=end

