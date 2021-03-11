/*
 * @lc app=leetcode.cn id=227 lang=golang
 *
 * [227] 基本计算器 II
 */

// @lc code=start
// 一次扫描字符串，将加号对应的数字直接压入栈中，将减号对应的数字的相反数压入栈中
// 然后遇到乘除则直接先计算，将计算后的结果压入栈中
// 这样栈中就全是只需要进行加法的数字了
// 最后将栈中的数字累加即可
func calculate(s string) int {
	stack, preSign, tempNum, res := []int{}, '+', 0, 0
	for i, ch := range s {
		// 将数字字符串转换成数字
		isDigit := '0' <= ch && ch <= '9'
		if isDigit {
			tempNum = tempNum*10 + int(ch-'0')
		}
		if !isDigit && ch != ' ' || i == len(s)-1 {
			switch preSign {
			// 将加号对应的数字直接压入栈中，将减号对应的数字的相反数压入栈中
			case '+':
				stack = append(stack, tempNum)
			case '-':
				stack = append(stack, -tempNum)
				// 遇到乘除则直接先计算，将计算后的结果压入栈中
			case '*':
				stack[len(stack)-1] = stack[len(stack)-1] * tempNum
			case '/':
				stack[len(stack)-1] = stack[len(stack)-1] / tempNum
			}
			preSign = ch
			tempNum = 0
		}
	}
	// 将栈内数字累加
	for _, v := range stack {
		res += v
	}
	return res
}

// @lc code=end

