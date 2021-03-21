/*
 * @lc app=leetcode.cn id=73 lang=golang
 *
 * [73] 矩阵置零
 */

// @lc code=start
//遍历原始矩阵，如果发现如果某个元素 matrix[i][j] 为 0，
//我们将第 i 行和第 j 列的所有非零元素设成很大的负虚拟值（比如说 -1000000）。
//最后，我们便利整个矩阵将所有等于虚拟值（常量在代码中初始化为 MODIFIED）的元素设为 0。
func setZeroes(matrix [][]int) {
	modified := -10000000
	row, column := len(matrix), len(matrix[0])
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if matrix[i][j] == 0 {
				for k := 0; k < row; k++ {
					if matrix[k][j] != 0 {
						matrix[k][j] = modified
					}
				}
				for k := 0; k < column; k++ {
					if matrix[i][k] != 0 {
						matrix[i][k] = modified
					}
				}
			}
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if matrix[i][j] == modified {
				matrix[i][j] = 0
			}
		}
	}
	return
}

// @lc code=end

