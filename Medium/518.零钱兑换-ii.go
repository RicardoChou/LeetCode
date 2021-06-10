/*
 * @lc app=leetcode.cn id=518 lang=golang
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
// 用dp[x]表示金额之和等于x的硬币组合数，目标是求dp[amount]
// 边界条件：dp[0]=1,因为金额之和为0的组合只有一种
// 对于面额为coin 的硬币，当coin≤i≤amount时
// 如果存在一种硬币组合的金额之和等于i−coin
// 则在该硬币组合中增加一个面额为coin的硬币，即可得到一种金额之和等于i的硬币组合。
// 因此需要遍历coins
// 对于其中的每一种面额的硬币，更新数组 \textit{dp}dp 中的每个大于或等于该面额的元素的值。
func change(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			dp[i] += dp[i-coin]
		}
	}
	return dp[amount]
}

// @lc code=end

