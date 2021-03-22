/*
 * @lc app=leetcode.cn id=191 lang=golang
 *
 * [191] 位1的个数
 */

// @lc code=start
// 辗转除2法
func hammingWeight(num uint32) int {
	res := 0
	for num > 0 {
		if num%2 == 1 {
			res++
		}
		num /= 2
	}
	return res
}

// @lc code=end

