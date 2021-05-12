/*
 * @lc app=leetcode.cn id=1310 lang=golang
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
func xorQueries(arr []int, queries [][]int) []int {
	xors := make([]int, len(arr)+1)
	for i, v := range arr {
		xors[i+1] = xors[i] ^ v
	}
	res := make([]int, len(queries))
	for i, q := range queries {
		res[i] = xors[q[0]] ^ xors[q[1]+1]
	}
	return res
}

// @lc code=end

