/*
 * @lc app=leetcode.cn id=424 lang=golang
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
package main

// 双指针法
func characterReplacement(s string, k int) int {
	// 枚举字符串中的每一个位置作为右端点，找到其最远的左端点的位置，使得该区间内除了出现次数最多的那一类字符之外，剩余的字符数量不超过k个。
	// 每次右指针右移，如果区间仍然满足条件，那么左指针不移动，否则左指针至多右移一格，保证区间长度不减小。
	// 每次区间右移，我们更新右移位置的字符出现的次数，然后尝试用它更新重复字符出现次数的历史最大值，
	// 最后我们使用该最大值计算出区间内非最长重复字符的数量，以此判断左指针是否需要右移
	chCount := [26]int{}
	// maxChCount存储的是某个区间内最大重复字符的数目
	maxChCount, left := 0, 0
	// right是右指针指向的下标，ch是右端点的字符
	for right, ch := range s {
		// 每遇到一个字符都将其数目加一
		chCount[ch-'A']++
		// 更新该区间内最大重复字符出现的次数
		maxChCount = max(maxChCount, chCount[ch-'A'])
		// 如果说该区间内非最长重复字符的数量是大于k的，也就是经过k次转换后不能满足条件的，那就需要将左指针右移一位，重新规划区间
		// 右移一位是为了保证区间的长度不减少
		if right-left+1-maxChCount > k {
			// 左指针右移一位后，则需要将原先左指针对应的字符数目减去1
			chCount[s[left]-'A']--
			left++
		}
	}
	// 返回区间的长度
	return len(s) - left
}

// 辅助函数
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
