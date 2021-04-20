/*
 * @lc app=leetcode.cn id=28 lang=golang
 *
 * [28] 实现 strStr()
 */

// @lc code=start

// 暴力法
func strStr(haystack string, needle string) int {
	m, n := len(haystack), len(needle)
	if n == 0 {
		return 0
	}
	for i := 0; i <= m-n; i++ {
		// 每次生成一个haystack的切片来和needle比较
		if haystack[i:i+n] == needle {
			return i
		}
	}
	return -1
}

// @lc code=end

