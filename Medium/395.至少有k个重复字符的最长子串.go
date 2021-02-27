/*
 * @lc app=leetcode.cn id=395 lang=golang
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
// 分治法，如果一个字符在整个字符串中出现的次数小于k，则所有包含它的子字符串一定不满足条件
// 那么就可以将这个字符作为分割符,查找其他子串的长度
func longestSubstring(s string, k int) int {
	// 字符计数
	charNum := make(map[rune]int)
	for _, v := range s {
		charNum[v]++
	}
	var split []int
	// 找到所有个数少于k的字符，将它们作为分割符
	for index, v := range s {
		if charNum[v] < k {
			split = append(split, index)
		}
	}
	// 如果所有字符出现次数都大于k，则整个字符串都满足
	if len(split) == 0 {
		return len(s)
	}
	// 将最右边的字符串加入split
	split = append(split, len(s))
	res, left := 0, 0
	for _, v := range split {
		// 总长度不超过已知最长的就没必要比较了
		if v-left+1 <= res {
			continue
		}
		res = max(res, longestSubstring(s[left:v], k))
		left = v + 1
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

