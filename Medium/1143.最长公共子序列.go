/*
 * @lc app=leetcode.cn id=1143 lang=golang
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
// dp[i][j]表示text1[0:i]与text2[0:j]的最长公共子序列
// 边界条件：dp[0][0]也就是text1[0:0]与text2[0:0]的最长公共子序列是0，也就是dp[0][0]=0
// 转移方程：当text1[i-1]==text2[j-1]的时候，dp[i][j]=dp[i-1][j-1]+1
// 当text1[i-1]!=text2[j-1]的时候，有两种可能：
// 1.text1[0:i-1]与text2[0:j]的最长公共子序列，也就是dp[i-1][j]
// 2.text1[0:i]与text2[0:j-1]的最长公共子序列，也就是dp[i][j-1]
// 取两者的较大者
func longestCommonSubsequence(text1 string, text2 string) int {
	size1, size2 := len(text1), len(text2)
	dp := make([][]int, size1+1)
	for i := range dp {
		dp[i] = make([]int, size2+1)
	}
	dp[0][0] = 0
	for i, c1 := range text1 {
		for j, c2 := range text2 {
			if c1 == c2 {
				dp[i+1][j+1] = dp[i][j] + 1
			} else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
			}
		}
	}
	return dp[size1][size2]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

