/*
 * @lc app=leetcode.cn id=115 lang=golang
 *
 * [115] 不同的子序列
 */

// @lc code=start
// 动态规划：从尾部向头部DP。假设字符串s和t的长度分别为m和n。如果t是s的子序列，则s的长度一定大于或等于t的长度
// 即只有当m≥n时，t才可能是s的子序列。如果m<n，则t一定不是s的子序列，因此直接返回0。
// 边界情况：当 j=n时，t[j:]为空字符串，由于空字符串是任何字符串的子序列，因此对任意0≤i≤m，有dp[i][n]=1；
// 当i=m且j<n时，s[i:]为空字符串，t[[j:]为非空字符串，由于非空字符串不是空字符串的子序列，因此对任意0≤j<n，有dp[m][j]=0。
// 当i<m且j<n时，考虑dp[i][j]的计算：
// 1.如果s[i]==t[j]:
// 	 1.1.如果用s[i]与t[j]来进行匹配，则考虑t[j+1:]作为s[i+1:]的子序列，子序列数为dp[i+1][j+1]；
// 	 1.2.如果不用s[i]与t[j]来进行匹配，而是用s中其他的字符来与t[j]进行匹配，那么t[j:]作为s[i+1:]的子序列，子序列数为dp[i+1][j]。
// 所以s[i]==t[j]时，有dp[i][j]=dp[i+1][j+1]+dp[i+1][j]。
// 2.如果s[i]!=t[j]:
// 那么s[i]肯定无法用于与t[j]进行匹配，所以s[i]!=t[j]时，dp[i][j]=dp[i+1][j]
func numDistinct(s string, t string) int {
	m, n := len(s), len(t)
	if m < n {
		return 0
	}
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][n] = 1
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == t[j] {
				dp[i][j] = dp[i+1][j+1] + dp[i+1][j]
			} else {
				dp[i][j] = dp[i+1][j]
			}
		}
	}
	return dp[0][0]
}

// @lc code=end

