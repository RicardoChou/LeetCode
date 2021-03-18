/*
 * @lc app=leetcode.cn id=452 lang=golang
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
func findMinArrowShots(points [][]int) int {
	size := len(points)
	// 特殊情况
	if size == 0 {
		return 0
	}
	// 将数组按照右端点从小到大排序
	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})
	// 初始最右端点设为第一个区间的右端点
	res, right := 1, points[0][1]
	for _, e := range points[1:] {
		// 如果最右端点在这个区间之间，那么这个区间就不需要额外的弓箭来射击
		if right >= e[0] && right <= e[1] {
			continue
			// 如果最右端点不在这个区间之间，那么就需要额外的弓箭来射击，弓箭数加1，同时更新最右端点
		} else {
			res++
			right = e[1]
		}
	}
	return res
}

// @lc code=end

