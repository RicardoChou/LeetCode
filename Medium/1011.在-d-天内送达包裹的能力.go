/*
 * @lc app=leetcode.cn id=1011 lang=golang
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
// 值域范围内二分法，船重量范围已知，最小是weights的最大值（只有满足weights中最大才能完成所有），也就是左边界l，
// 最大是weights之和，右边界r，从最大最小范围内找到一个，满足D天内搬运，
// 计算当运载能力是mid的时候所需要天数day
// 若day > D 说明运载能力小了，l = mid+1
// 若day <= D,说明运载能力可以，但是不一定符合最小的要求，由于l<r,故r=mid而不是mid-1
// 直到区间缩小到l == r
func shipWithinDays(weights []int, D int) int {
	left, right, mid := 0, 0, 0
	// 初始左边界是weights的最大值，初始右边界是weights所有元素的和
	for _, v := range weights {
		right += v
		if v > left {
			left = v
		}
	}
	for left < right {
		mid = (left + right) / 2
		if canFinish(weights, mid, D) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

// 指定运载能力cap能否在D天内运完所有货物
func canFinish(weights []int, cap, D int) bool {
	daySum, day := 0, 1
	for i := 0; i < len(weights); {
		// 如果加上当天的货物重量还没超过当前的运载能力就把它加上去
		if daySum+weights[i] <= cap {
			daySum += weights[i]
			i++
			// 如果加上当天的货物重量超过当前的运载能力，就得重新计算所需天数
		} else {
			daySum, day = 0, day+1
		}
	}
	return day <= D
}

// @lc code=end

