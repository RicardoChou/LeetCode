/*
 * @lc app=leetcode.cn id=832 lang=golang
 *
 * [832] 翻转图像
 */

// @lc code=start

// 翻转的同时用异或运算取反，1^1=0 0^1=1
func flipAndInvertImage(A [][]int) [][]int {
	m := len(A)
	for i := 0; i < m; i++ {
		n := len(A[i])
		for j := 0; j < (n+1)/2; j++ {
			A[i][j], A[i][n-1-j] = A[i][m-1-j]^1, A[i][j]^1
		}
	}
	return A
}

// @lc code=end
