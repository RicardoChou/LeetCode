/*
 * @lc app=leetcode.cn id=154 lang=golang
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
func findMin(nums []int) int {
	low, high := 0, len(nums)-1
	for low < high {
		mid := low + (high-low)/2
		// 如果右端点值比中间点值大，说明右半部分不可能存在最小值，可以直接省去
		if nums[mid] < nums[high] {
			high = mid
			// 如果右端点值比中间点值小，说明左半部分不可能存在最小值，可以直接省去
		} else if nums[mid] > nums[high] {
			low = mid + 1
			// 如果右端点值和中间点值一样，那就右端点缩至不一样
		} else {
			high--
		}
	}
	return nums[low]
}

// @lc code=end

