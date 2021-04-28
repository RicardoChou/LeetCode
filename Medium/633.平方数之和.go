/*
 * @lc app=leetcode.cn id=633 lang=golang
 *
 * [633] 平方数之和
 */

// @lc code=start
// 双指针：左指针从0开始右移，右指针从根号c开始左移
func judgeSquareSum(c int) bool {
	i, j := 0, int(math.Sqrt(float64(c)))
	for i <= j {
		sum := i*i + j*j
		if sum == c {
			return true
		} else if sum < c {
			i++
		} else {
			j--
		}
	}
	return false
}

// @lc code=end

