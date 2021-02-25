/*
 * @lc app=leetcode.cn id=867 lang=golang
 *
 * [867] 转置矩阵
 */

// @lc code=start
package main

func transpose(matrix [][]int) [][]int {
	m := len(matrix)
	n := len(matrix[0])
	// 新建一个二维数组，转置行和列
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res[i][j] = matrix[j][i]
		}
	}
	return res
}

// @lc code=end
