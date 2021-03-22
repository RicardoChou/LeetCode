/*
 * @lc app=leetcode.cn id=633 lang=golang
 *
 * [633] 平方数之和
 */

// @lc code=start
func judgeSquareSum(c int) bool {
	for i, j := 0, int(math.Sqrt(float64(c))); i <= j; {
		num := i*i + j*j
		if num == c {
			return true
		} else if num < c {
			i++
		} else {
			j--
		}
	}
	return false
}

// @lc code=end

