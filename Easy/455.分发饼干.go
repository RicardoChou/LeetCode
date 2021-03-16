/*
 * @lc app=leetcode.cn id=455 lang=golang
 *
 * [455] 分发饼干
 */

// @lc code=start

// 贪心算法
// 对两个数组进行排序，给剩余孩子里最小胃口的孩子分配最小的能饱腹的饼干
func findContentChildren(g []int, s []int) int {
	// 对两个数组进行排序
	sort.Ints(g)
	sort.Ints(s)
	childrenNum, CookieNum := len(g), len(s)
	i, j := 0, 0
	for i < childrenNum && j < CookieNum {
		// 找到了能够满足最小的胃口的孩子的饼干大小
		if g[i] <= s[j] {
			i++
		}
		// 找能够满足当前最小胃口的孩子的最小的饼干
		j++
	}
	return i
}

// @lc code=end
