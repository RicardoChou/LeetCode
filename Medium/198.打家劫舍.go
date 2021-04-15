/*
 * @lc app=leetcode.cn id=198 lang=golang
 *
 * [198] 打家劫舍
 */

// @lc code=start
// 动态规划
// dp[i]表示偷取前i个房间之后能够获得的钱
// 因为不能连着偷两户人家，所以要分情况讨论
// 1.如果说不偷第i个房子，那么dp[i]=dp[i-1]
// 2.如果说偷第i个房子，那么dp[i]=dp[i-2]+nums[i]
// 假如第i-1间房子没有被偷，那么dp[i-1]=dp[i-2],那么dp[i]=dp[n]+nums[i]=dp[i-1]+nums[i]，也就是上面两种情况是一种情况其实
// 假设第 n 间被偷，那么此时 dp[n+1]=dp[n]+num 不可取 ，因为偷了第 n 间就不能偷第 n+1 间
// 边界条件：dp[0]=nums[0]或者dp[1]=max(nums[0],nums[1])
// 状态转移方程：dp[i]=max(dp[i-1],dp[i-2]+nums[i])

func rob(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	if size == 1 {
		return nums[0]
	}
	dp := make([]int, size)
	dp[0] = nums[0]
	dp[1] = max(nums[0], nums[1])
	for i := 2; i < size; i++ {
		dp[i] = max(dp[i-1], dp[i-2]+nums[i])
	}
	return dp[size-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

