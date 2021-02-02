/*
 * @lc app=leetcode.cn id=455 lang=golang
 *
 * [455] 分发饼干
 */

// @lc code=start

// 贪心算法
// 对两个数组进行排序，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干
func findContentChildren(g []int, s []int) int {
	// 对两个数组进行排序
	sort.Ints(g)
	sort.Ints(s)
	ChildrenNum, CookieNum := len(g), len(s)
	i, j := 0, 0
	for i < ChildrenNum && j < CookieNum {
		// 剩余孩子中最小饥饿度的孩子分配了最小的能饱腹的饼干后，将孩子数组后移一位继续查找
		if g[i] <= s[j] {
			i++
		}
		// 查找最小的能饱腹的饼干
		j++
	}
	// 返回能够满足的孩子数量
	return i
}

// @lc code=end
