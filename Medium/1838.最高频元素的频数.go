/*
 * @lc app=leetcode.cn id=1838 lang=golang
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
func maxFrequency(nums []int, k int) (maximum int) {
	// 先对数组进行排序
	sort.Ints(nums)
	prefix := make([]int, len(nums)+1)
	// 前缀和存储数组中每个数与之前的数的和
	for i := range nums {
		prefix[i+1] = prefix[i] + nums[i]
	}
	left, right := 0, 0
	for right < len(nums) {
		// 假设所有的数都变成了右边界的数，然后计算窗口内数字都变成右边界所需要的变化次数
		for nums[right]*(right-left)-(prefix[right]-prefix[left]) > k {
			left++
		}
		// 更新最大值
		if maximum < right-left+1 {
			maximum = right - left + 1
		}
		// 扩大右边界
		right++
	}
	return
}

// @lc code=end

