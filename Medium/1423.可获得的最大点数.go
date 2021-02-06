/*
 * @lc app=leetcode.cn id=1423 lang=golang
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start

// k张卡牌是开头和末尾拿的，所以剩下的n-k张卡牌是连续的
// 选择一个n-k长度的滑动窗口，找出滑动窗口内点数之和的最小值
// 用n张卡牌点数之和减去滑动窗口内点数之和就是k张卡牌的最大值
func maxScore(cardPoints []int, k int) int {
	total := 0
	n := len(cardPoints)
	// n张卡牌点数之和
	for _, v := range cardPoints {
		total += v
	}
	sum := 0
	// 长度为n-k的滑动窗口
	winSize := n - k
	for i := 0; i < winSize; i++ {
		sum += cardPoints[i]
	}
	// 滑动窗口内点数最小值初始化
	minSum := sum
	// 更新滑动窗口的最小值
	// 每向右移动一位，就减去原来左窗口的值，再加上新加入的右窗口的值
	for i := winSize; i < n; i++ {
		sum += cardPoints[i] - cardPoints[i-winSize]
		minSum = int(math.Min(float64(sum), float64(minSum)))
	}
	return total - minSum
}

// @lc code=end
