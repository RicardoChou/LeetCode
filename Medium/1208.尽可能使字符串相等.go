/*
 * @lc app=leetcode.cn id=1208 lang=golang
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
package main

// 滑动窗口左右边界双指针
func equalSubstring(s string, t string, maxCost int) int {
	// 每个窗口内转换所需要的开销
	cost := 0
	// 左右边界双指针
	left, right := 0, 0
	// 右边界指针后移来扩大窗口
	for ; right < len(s); right++ {
		// 计算当前窗口的开销
		cost += abs(int(s[right]) - int(t[right]))
		// 如果当前窗口的开销大于给定最大开销，则需要将左边界指针后移使窗口变小一位，且要减去左边界转换开销
		if cost > maxCost {
			cost -= abs(int(s[left]) - int(t[left]))
			left++
		}
	}
	// 在第一个窗口后，我们没必要再去计算长度小于该窗口的子串，
	// 因为最后求的长度，并不是实际子串，所以len(s)-l一定代表了某一满足条件的最长子串
	return len(s) - left
}

// 辅助函数求绝对值
func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}

// @lc code=end
