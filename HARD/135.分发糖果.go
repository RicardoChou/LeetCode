/*
 * @lc app=leetcode.cn id=135 lang=golang
 *
 * [135] 分发糖果
 */

// @lc code=start
// 贪心算法：先将每个孩子的糖果数初始化为1
// 先从左往右遍历，如果右边的孩子的分数比左边高，则他的糖果数比左边的多1
// 再从右往左遍历，如果左边的孩子的分数比右边高，并且左边孩子的糖果数不大于右边，则左边孩子的糖果数比右边的多1
// 这里的贪心策略是只考虑每个孩子左右两边的糖果数量，而不从全局比较
func candy(ratings []int) int {
	size := len(ratings)
	// 特殊情况
	if size < 2 {
		return size
	}
	// 初始化糖果数数组
	candyNum := make([]int, size)
	for index, _ := range candyNum {
		candyNum[index]++
	}
	// 第一遍扫描右边比左边大则右边比左边多1
	for i := 1; i < size; i++ {
		if ratings[i] > ratings[i-1] {
			candyNum[i] = candyNum[i-1] + 1
		}
	}
	// 在第二遍扫描修改糖果数量的同时进行糖果总个数的计算
	total := candyNum[size-1]
	for i := size - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] && candyNum[i] <= candyNum[i+1] {
			candyNum[i] = candyNum[i+1] + 1
		}
		total += candyNum[i]
	}
	return total
}

// @lc code=end

