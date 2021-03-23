/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
func searchRange(nums []int, target int) []int {
	var res []int

	if len(nums) == 0 {
		res = append(res, -1, -1)
		return res
	}

	// 上界需要减1
	low, high := findLowBound(nums, target), findHighBound(nums, target)-1
	if low == len(nums) || nums[low] != target {
		res = append(res, -1, -1)
		return res
	}
	res = append(res, low, high)
	return res
}

// 找下界的复转函数
func findLowBound(nums []int, target int) int {
	low, high := 0, len(nums)
	var mid int
	for low < high {
		mid = (low + high) / 2
		if nums[mid] >= target {
			high = mid
		} else {
			low = mid + 1
		}
	}
	return low
}

// 找上界的辅助函数
func findHighBound(nums []int, target int) int {
	low, high := 0, len(nums)
	var mid int
	for low < high {
		mid = (low + high) / 2
		if nums[mid] > target {
			high = mid
		} else {
			low = mid + 1
		}
	}
	return low
}

// @lc code=end

