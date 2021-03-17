/*
 * @lc app=leetcode.cn id=435 lang=golang
 *
 * [435] 无重叠区间
 */

// @lc code=start
// 贪心算法：如果每次都选择右端点最小的区间，那么留下来的区间就回越大，理论上不重叠的区间的个数也就越多
// 先将所有区间按照右端点从小到大排序，将第一个区间的右端点作为初始最右端点
// 然后遍历数组，如果不重叠就加入计数，同时将最右端点进行更新
func eraseOverlapIntervals(intervals [][]int) int {
	size := len(intervals)
	// 特殊情况
	if size == 0 {
		return 0
	}
	// 按照右端点从小到大排序
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})
	// 初始总右端点设为第一个区间的右端点
	res, right := 1, intervals[0][1]
	for _, e := range intervals[1:] {
		// 如果下一个区间的左端点在最右端点的右边（或者相同），则该区间不重叠
		if e[0] >= right {
			res++
			// 更新最右端点
			right = e[1]
		}
	}
	// 返回的是需要删除的区间个数
	return size - res
}

// @lc code=end

