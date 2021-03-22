/*
 * @lc app=leetcode.cn id=680 lang=golang
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
func validPalindrome(s string) bool {
	flag1, flag2 := true, true
	for low, high := 0, len(s)-1; low < high; {
		if s[low] == s[high] {
			low++
			high--
		} else {
			for i, j := low+1, high; i < j; {
				if s[i] == s[j] {
					i++
					j--
				} else {
					flag1 = false
					break
				}
			}
			for i, j := low, high-1; i < j; {
				if s[i] == s[j] {
					i++
					j--
				} else {
					flag2 = false
					break
				}
			}
			return flag1 || flag2
		}
	}
	return true
}

// @lc code=end

