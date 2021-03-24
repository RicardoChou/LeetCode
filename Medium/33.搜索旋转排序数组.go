/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	left, right, mid := 0, len(nums)-1, 0
	for left <= right {
		mid = (left + right) / 2
		if nums[mid] == target {
			return mid
		}
		// [left,mid] 连续递增
		if nums[left] <= nums[mid] {
			if nums[left] <= target && target <= nums[mid] {
				right = mid - 1 // 在左侧 [left,mid) 查找
			} else {
				left = mid + 1
			}
		} else { // [mid,right] 连续递增
			if nums[mid] <= target && target <= nums[right] {
				left = mid + 1 // 在右侧 (mid,right] 查找
			} else {
				right = mid - 1
			}
		}
	}
	return -1
}

// @lc code=end

