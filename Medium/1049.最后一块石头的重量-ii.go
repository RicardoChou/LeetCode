/*
 * @lc app=leetcode.cn id=1049 lang=golang
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, stone := range stones {
		sum += stone
	}
	dp := make([]int, sum/2+1)
	for _, stone := range stones {
		for j := sum / 2; j >= stone; j-- {
			dp[j] = max(dp[j], dp[j-stone]+stone)
		}
	}
	return sum - dp[sum/2]*2
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// @lc code=end

