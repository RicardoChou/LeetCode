/*
 * @lc app=leetcode.cn id=763 lang=golang
 *
 * [763] 划分字母区间
 */

// @lc code=start
func partitionLabels(S string) []int {
	lastIndex := make(map[rune]int)
	s := []rune(S)
	res := []int{}
	// 特殊情况
	if len(s) == 0 {
		return res
	}
	// 存储每个字符最后出现的index
	for index, e := range s {
		lastIndex[e] = index
	}
	left, right := 0, 0
	for index, e := range s {
		// 如果扫描到的字符使得该区间向右扩张，则更新最右端点
		if lastIndex[e] > right {
			right = lastIndex[e]
		}
		// 如果扫描到了该区间的最右端点，则计算该区间长度并更新最左端点
		if index == right {
			res = append(res, right-left+1)
			left = right + 1
		}
	}
	return res
}

// @lc code=end

