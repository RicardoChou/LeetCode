/*
 * @lc app=leetcode.cn id=80 lang=golang
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
// 双指针法
func removeDuplicates(nums []int) int {
	size := len(nums)
	// 特殊情况
	if size <= 2 {
		return size
	}
	slow, fast := 2, 2
	for fast < size {
		// 如果有两个重复的数字的话，就覆盖即可
		if nums[slow-2] != nums[fast] {
			nums[slow] = nums[fast]
			slow++
		}
		fast++
	}
	return slow
}

// @lc code=end

