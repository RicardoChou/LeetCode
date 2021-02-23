/*
 * @lc app=leetcode.cn id=1052 lang=golang
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
// 实际上就是给定了一个定长为X的窗口，比较将窗口内的不开心的时间转换成开心的时候的收益最大化
package main

func maxSatisfied(customers []int, grumpy []int, X int) int {
	// 先计算没有转换心情之前，所有的收益
	regular := 0
	// 将窗口内心情转换后的收益再累加上去
	bonus := 0
	for i := 0; i < len(customers); i++ {
		// 心情好的时候才能有收益
		if grumpy[i] == 0 {
			regular += customers[i]
		}
	}
	// 长度为X的初始滑动窗口，将原本为不开心的时间的收益累加进去
	for i := 0; i < X; i++ {
		bonus += customers[i] * grumpy[i]
	}
	// 初始滑动窗口经过转换后得到的最大收益
	maxSalary := regular + bonus
	for i := X; i < len(customers); i++ {
		bonus = bonus - customers[i-X]*grumpy[i-X] + customers[i]*grumpy[i]
		maxSalary = max(regular+bonus, maxSalary)
	}
	return maxSalary
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
