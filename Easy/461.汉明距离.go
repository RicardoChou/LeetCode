/*
 * @lc app=leetcode.cn id=461 lang=golang
 *
 * [461] 汉明距离
 */

// @lc code=start
func hammingDistance(x int, y int) int {
	res := 0
	temp1, temp2 := make([]int, 0), make([]int, 0)
	for x > 0 || y > 0 {
		temp1 = append(temp1, x%2)
		temp2 = append(temp2, y%2)
		x /= 2
		y /= 2
	}
	for i := range temp1 {
		if temp1[i] != temp2[i] {
			res++
		}
	}
	return res
}

// @lc code=end

