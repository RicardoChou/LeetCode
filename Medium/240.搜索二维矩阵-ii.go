/*
 * @lc app=leetcode.cn id=240 lang=golang
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
package main

// 每一次都选择矩阵最右上角的元素进行比较，不断缩小矩阵的大小
func searchMatrix(matrix [][]int, target int) bool {
	//	特殊情况，矩阵为空
	if len(matrix) == 0 {
		return false
	}
	// 矩阵最右上角的元素
	rowNum, columnNum := 0, len(matrix[0])-1
	for rowNum < len(matrix) && columnNum >= 0 {
		// 如果最右上角的元素等于target，那就直接返回true
		if matrix[rowNum][columnNum] == target {
			return true
			// 如果最右上角的元素小于target，则target可能在该元素下方区域，则将该行去除
		} else if matrix[rowNum][columnNum] < target {
			rowNum++
			// 如果最右上角的元素大于target，则target可能在该元素左方区域，则将该列去除
		} else {
			columnNum--
		}
	}
	return false
}

// @lc code=end
