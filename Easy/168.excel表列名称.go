/*
 * @lc app=leetcode.cn id=168 lang=golang
 *
 * [168] Excel表列名称
 */

// @lc code=start
func convertToTitle(columnNumber int) string {
	res := ""
	for columnNumber != 0 {
		if columnNumber == 26 {
			res = "Z" + res
			return res
		} else if columnNumber%26 == 0 {
			res = "Z" + res
			columnNumber = columnNumber/26 - 1
		} else {
			res = string(columnNumber%26-1+'A') + res
			columnNumber = columnNumber / 26
		}
	}
	return res
}

// @lc code=end

