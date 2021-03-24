/*
 * @lc app=leetcode.cn id=456 lang=golang
 *
 * [456] 132模式
 */

// @lc code=start
// 从右往左枚举，用单调栈维护所有遍历过的元素，作为次大值的候选元素
// 每扫描到一个元素的同时，判断它是否可以作为最大值，如果可以作为最大值
// 则单调栈中所有小于该元素的元素都可以作为次大值，我们将这些元素都移出单调栈
// 并且选择被移除的元素的最大值作为次大值
// 在单调栈中，从栈底到栈顶的元素是严格单调递减的。
// 当给定阈值x时，我们只需要不断地弹出栈顶的元素，直到栈为空或者x严格小于栈顶元素。
// 此时我们再将x入栈，这样就维护了栈的单调性。

func find132pattern(nums []int) bool {
	n := len(nums)
	candidateK := []int{nums[n-1]}
	maxK := math.MinInt64

	for i := n - 2; i >= 0; i-- {
		// 判断nums[i]是否可以作为最小值，如果该值小于次大值，则找到最小值，则存在
		if nums[i] < maxK {
			return true
		}
		// 我们将nums[i]不断地与单调栈栈顶的元素进行比较，如果nums[i]较大，那么栈顶元素可以真正作为次大值，将其弹出并更新maxK；
		for len(candidateK) > 0 && nums[i] > candidateK[len(candidateK)-1] {
			maxK = candidateK[len(candidateK)-1]
			candidateK = candidateK[:len(candidateK)-1]
		}
		if nums[i] > maxK {
			// 将nums[i]作为候选次大值加入单调栈中
			candidateK = append(candidateK, nums[i])
		}
	}
	return false
}

// @lc code=end

