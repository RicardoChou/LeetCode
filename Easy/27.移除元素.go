/*
 * @lc app=leetcode.cn id=27 lang=golang
 *
 * [27] 移除元素
 */

// @lc code=start
// 双指针优化
// 如果左指针的值等于val，那么就将右指针的值赋给左指针指向的值
func removeElement(nums []int, val int) int {
	left, right := 0, len(nums)
	for left < right {
		if nums[left] == val {
			// 如果左指针的值等于val，那么就将右指针的值赋给左指针指向的值
			nums[left] = nums[right-1]
			// 右指针左移，左指针不动，因为有可能原来右指针的值还是等于val，所以需要下一次循环的时候重新判断
			right--
		} else {
			// 左指针的值不等于val就可以直接右移一位
			left++
		}
	}
	return left
}

// @lc code=end

