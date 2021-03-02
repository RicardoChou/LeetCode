/*
 * @lc app=leetcode.cn id=304 lang=golang
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
// 二维矩阵存储每一行的前缀和
type NumMatrix struct {
	sumMatrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	sumMatrix := make([][]int, len(matrix))
	// 遍历每一行，计算每一行的一维前缀和
	for i := 0; i < len(matrix); i++ {
		sumMatrix[i] = make([]int, len(matrix[i])+1)
		for j, v := range matrix[i] {
			sumMatrix[i][j+1] = sumMatrix[i][j] + v
		}
	}
	return NumMatrix{sumMatrix}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	var sum int
	// 计算从row1到row2的每一行，并用每一行的前缀和求出每一行的总和
	for i := row1; i <= row2; i++ {
		sum += this.sumMatrix[i][col2+1] - this.sumMatrix[i][col1]
	}
	return sum
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
// @lc code=end

