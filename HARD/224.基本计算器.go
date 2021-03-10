/*
 * @lc app=leetcode.cn id=224 lang=golang
 *
 * [224] 基本计算器
 */

// @lc code=start
// 每遇到一个-号，则之后括号内的符号都需要被翻转
// 可以使用一个sign={-1.+1}标记，来记录当前该符号的正负性
// 用一个栈stack来保存当前位置的符号的真实正负性
// 如果当前遇到了+号，则更新sign ← stack.top()；如果遇到了遇到了-号，则更新sign ← −stack.top()。
func calculate(s string) int {
	sign := 1
	stack := []int{1}
	res := 0
	for i := 0; i < len(s); {
		switch s[i] {
		// 遇到空格则跳过
		case ' ':
			i++
			// 遇到+号则更新sign ← stack.top()
		case '+':
			sign = stack[len(stack)-1]
			i++
			// 遇到-号则更新sign ← −stack.top()
		case '-':
			sign = -stack[len(stack)-1]
			i++
			// 遇到（则将当前的sign压入栈中，除非后续遇到），否则该括号区间内的数字的正负性都将随之变化
		case '(':
			stack = append(stack, sign)
			i++
			// 遇到）则将栈顶的sign弹出，表明该括号内数字的正负性已经全部变化过了
		case ')':
			stack = stack[:len(stack)-1]
			i++
			// 遇到数字字符将其转化为数字
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			temp := 0
			for ; i < len(s) && '0' <= s[i] && s[i] <= '9'; i++ {
				temp = temp*10 + int(s[i]-'0')
			}
			res += temp * sign
		}
	}
	return res
}

// @lc code=end

