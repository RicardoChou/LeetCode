/*
 * @lc app=leetcode.cn id=377 lang=golang
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
//用dp[x]表示选取的元素之和等于x的方案数，目标是求dp[target]。
//边界是 dp[0]=1。只有当不选取任何元素时，元素之和才为 0，因此只有 1 种方案
//遍历 i 从 1 到 target，对于每个 i，进行如下操作：遍历数组 nums 中的每个元素 num，当 num≤i 时，将 dp[i−num] 的值加到 dp[i]。

func combinationSum4(nums []int, target int) int {
	dp := make([]int, target+1)
	dp[0] = 1
	for i := 1; i <= target; i++ {
		for _, num := range nums {
			if num <= i {
				dp[i] += dp[i-num]
			}
		}
	}
	return dp[target]
}

// @lc code=end

