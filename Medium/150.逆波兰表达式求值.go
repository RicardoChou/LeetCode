/*
 * @lc app=leetcode.cn id=150 lang=golang
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
// 逆波兰表达式的特点是：没有括号，运算符总是放在和它相关的操作数之后。因此，逆波兰表达式也称后缀表达式。
func evalRPN(tokens []string) int {
	stack := []int{}
	for _, token := range tokens {
		// strcon.Atoi是将字符转换成数值型
		value, err := strconv.Atoi(token)
		// 如果是数字则压入栈
		if err == nil {
			stack = append(stack, value)
			// 是运算符则进行相应的运算
		} else {
			num1, num2 := stack[len(stack)-2], stack[len(stack)-1]
			stack = stack[:len(stack)-2]
			switch token {
			case "+":
				stack = append(stack, num1+num2)
			case "-":
				stack = append(stack, num1-num2)
			case "*":
				stack = append(stack, num1*num2)
			case "/":
				stack = append(stack, num1/num2)
			}
		}
	}
	return stack[0]
}

// @lc code=end

