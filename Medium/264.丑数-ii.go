/*
 * @lc app=leetcode.cn id=264 lang=golang
 *
 * [264] 丑数 II
 */

// @lc code=start
// 定义一个数组dp，dp[n]就是第n个丑数
// 初始条件：dp[1]=1
// 定义三个指针，p2，p3，p5，用来表示下一个丑数是当前指针指向的丑数乘以对应的质因数。初始时，三个指针的值都是1。
// 2<=i<=n时，dp[i]=min(dp[p2]*2,dp[p3]*3,dp[p5]*5),并且比较dp[p2],dp[p3],dp[p5]和dp[i]是否相同，相同则对应指针加1
func nthUglyNumber(n int) int {
	dp := make([]int, n+1)
	dp[1] = 1
	p2, p3, p5 := 1, 1, 1
	for i := 2; i <= n; i++ {
		m2, m3, m5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
		dp[i] = min(min(m2, m3), m5)
		if dp[i] == m2 {
			p2++
		}
		if dp[i] == m3 {
			p3++
		}
		if dp[i] == m5 {
			p5++
		}
	}
	return dp[n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end

