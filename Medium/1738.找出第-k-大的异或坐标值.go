/*
 * @lc app=leetcode.cn id=1738 lang=golang
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
//二维数组前缀和
func kthLargestValue(matrix [][]int, k int) int {
	n := len(matrix)
	m := len(matrix[0])
	nmatrix := make([][]int, n)
	for i := 0; i < n; i++ {
		nmatrix[i] = make([]int, m)
	}
	nmatrix[0][0] = matrix[0][0]
	for i := 1; i < n; i++ {
		nmatrix[i][0] = nmatrix[i-1][0] ^ matrix[i][0]
	}
	for i := 1; i < m; i++ {
		nmatrix[0][i] = nmatrix[0][i-1] ^ matrix[0][i]
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			nmatrix[i][j] = nmatrix[i-1][j] ^ nmatrix[i][j-1] ^ matrix[i][j] ^ nmatrix[i-1][j-1]
		}
	}
	nums := []int{}
	for _, row := range nmatrix {
		for _, column := range row {
			nums = append(nums, column)
		}
	}
	sort.Ints(nums)
	return nums[len(nums)-k]
}

// @lc code=end

