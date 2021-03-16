/*
 * @lc app=leetcode.cn id=59 lang=golang
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
// 和56题类似
func generateMatrix(n int) [][]int {
	res := [][]int{}
	for i := 0; i < n; i++ {
		res = append(res, make([]int, n))
	}
	size := n * n
	// 左右边界
	left, right := 0, n-1
	// 上下边界
	up, down := 0, n-1
	num := 1
	for num <= size {
		// 从左到右填充，行不变，列变化
		for i := left; i <= right; i++ {
			res[up][i] = num
			num++
		}
		// 上边界收缩
		up++
		// 从上到下填充，列不变，行变化
		for i := up; i <= down; i++ {
			res[i][right] = num
			num++
		}
		// 右边界收缩
		right--
		// 从右往左填充，行不变，列变化
		for i := right; i >= left; i-- {
			res[down][i] = num
			num++
		}
		// 下边界收缩
		down--
		// 从下到上填充，列不变，行变化
		for i := down; i >= up; i-- {
			res[i][left] = num
			num++
		}
		// 左边界收缩
		left++
	}
	return res
}

// @lc code=end

