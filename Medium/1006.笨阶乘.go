/*
 * @lc app=leetcode.cn id=1006 lang=golang
 *
 * [1006] 笨阶乘
 */

// @lc code=start
func clumsy(N int) int {
	res := 0
	stack := []int{N}
	N--
	index := 0
	for N > 0 {
		switch index % 4 {
		case 0:
			stack[len(stack)-1] *= N
		case 1:
			stack[len(stack)-1] /= N
		case 2:
			stack = append(stack, N)
		case 3:
			stack = append(stack, -N)
		}
		index++
		N--
	}
	for _, val := range stack {
		res += val
	}
	return res
}

// @lc code=end

