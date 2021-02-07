/*
 * @lc app=leetcode.cn id=665 lang=golang
 *
 * [665] 非递减数列
 */

// @lc code=start
func checkPossibility(nums []int) bool {
	count := 0
	n := len(nums)
	for i := 1; i < n; i++ {
		if nums[i-1] > nums[i] {
			count++
			// 有两个递减的情况则直接返回false
			if count > 1 {
				return false
			}
			if i == 1 || (i > 1 && nums[i-2] < nums[i]) {
				nums[i-1] = nums[i]
			}
			if i > 1 && nums[i-2] > nums[i] {
				nums[i] = nums[i-1]
			}
		}
	}
	return true
}

// @lc code=end
