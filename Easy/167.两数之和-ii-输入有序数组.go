/*
 * @lc app=leetcode.cn id=167 lang=golang
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// 双指针法
func twoSum(numbers []int, target int) []int {
	res := []int{}
	size := len(numbers)
	i, j := 0, size-1
	for i < j {
		// 找到即退出循环
		if numbers[i]+numbers[j] == target {
			res = append(res, i+1, j+1)
			break
			// 比target小则左指针后移
		} else if numbers[i]+numbers[j] < target {
			i++
			// 比target大则右指针前移
		} else {
			j--
		}
	}
	return res
}

// @lc code=end

