/*
 * @lc app=leetcode.cn id=1047 lang=golang
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
// 用辅助栈，如果相邻则弹出栈，不相邻则压入栈，最后返回栈内字符即可
func removeDuplicates(S string) string {
	stack := []byte{}
	for i := range S {
		// 栈不空且是相邻的重复字符则弹出栈
		if len(stack) > 0 && stack[len(stack)-1] == S[i] {
			stack = stack[:len(stack)-1]
			// 否则压入栈
		} else {
			stack = append(stack, S[i])
		}
	}
	return string(stack)
}

// @lc code=end

