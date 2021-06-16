/*
 * @lc app=leetcode.cn id=852 lang=golang
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
func peakIndexInMountainArray(arr []int) int {
	for i := 1; i < len(arr); i++ {
		if arr[i-1] < arr[i] && arr[i] > arr[i+1] {
			return i
		}
	}
	return len(arr) - 1
}

// @lc code=end

