/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
// 双指针遍历即可
func removeDuplicates(nums []int) int {
	i, j := 0, 0
	size := len(nums)
	for j < size {
		if nums[i] != nums[j] {
			i++
			nums[i] = nums[j]
		}
		j++
	}
	return i + 1
}

// @lc code=end

