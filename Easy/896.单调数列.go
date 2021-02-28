/*
 * @lc app=leetcode.cn id=896 lang=golang
 *
 * [896] 单调数列
 */

// @lc code=start
func isMonotonic(A []int) bool {
	var isDec bool
	var isInc bool
	isDec = isDecMon(A)
	isInc = isIncMon(A)
	// 是递减或者递增都是单调函数
	return isDec || isInc
}

// 判断是否是递减函数
func isDecMon(A []int) bool {
	for i := 1; i < len(A); i++ {
		if A[i] > A[i-1] {
			return false
		}
	}
	return true
}

// 判断是否是递增函数
func isIncMon(A []int) bool {
	for i := 1; i < len(A); i++ {
		if A[i] < A[i-1] {
			return false
		}
	}
	return true
}

// @lc code=end

