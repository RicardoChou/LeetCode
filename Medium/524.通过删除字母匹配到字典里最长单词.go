/*
 * @lc app=leetcode.cn id=524 lang=golang
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
func findLongestWord(s string, dictionary []string) string {
	res := ""
	for _, v := range dictionary {
		if isInString(s, v) {
			// 按照长度排序，或长度相同按照字典序排序
			if len(v) > len(res) || (len(v) == len(res) && v < res) {
				res = v
			}
		}
	}
	return res
}

// 判断subString是否在String中的辅助函数
func isInString(s, t string) bool {
	sLen, tLen := len(s), len(t)
	if tLen <= 0 {
		return true
	}
	if sLen < tLen {
		return false
	}
	p1, p2 := 0, 0
	for p1 < sLen {
		if s[p1] == t[p2] {
			p1++
			p2++
		} else {
			p1++
		}
		if p2 == tLen {
			return true
		}
	}
	return false
}

// @lc code=end

