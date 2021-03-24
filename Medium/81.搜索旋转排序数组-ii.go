/*
 * @lc app=leetcode.cn id=81 lang=golang
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
// 二分查找：如果mid元素小于右端点，则说明右区间是排序好的，反之左区间是排序好的
// 在对应区间继续二分查找即可
func search(nums []int, target int) bool {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := (low + high) / 2
		if nums[mid] == target {
			return true
		}
		if nums[mid] == nums[low] {
			low++
		} else if nums[mid] <= nums[high] {
			if target > nums[mid] && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		} else {
			if target < nums[mid] && target >= nums[low] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		}
	}
	return false
}

// @lc code=end

