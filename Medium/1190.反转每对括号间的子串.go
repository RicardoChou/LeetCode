/*
 * @lc app=leetcode.cn id=1190 lang=golang
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
func reverseParentheses(s string) string {
	stack := [][]byte{}
	str := []byte{}
	for i := range s {
		// 遇到左括号则将临时字符串str加入栈中并且重置str
		if s[i] == '(' {
			stack = append(stack, str)
			str = []byte{}
			// 遇到右括号就将临时字符串str反转
		} else if s[i] == ')' {
			for left, right := 0, len(str); left < right/2; left++ {
				str[left], str[right-1-left] = str[right-1-left], str[left]
			}
			str = append(stack[len(stack)-1], str...)
			stack = stack[:len(stack)-1]
			// 遇到字符则将其加入临时字符串str
		} else {
			str = append(str, s[i])
		}
	}
	return string(str)
}

// @lc code=end

