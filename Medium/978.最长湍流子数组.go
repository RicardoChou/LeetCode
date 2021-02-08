/*
 * @lc app=leetcode.cn id=978 lang=golang
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
// 滑动窗口双指针
func maxTurbulenceSize(arr []int) int {
	n := len(arr)
	res := 1
	left, right := 0, 0
	for right < n-1 {
		// 窗口长度为1的特殊情况
		if left == right {
			// 如果长度为1的窗口不满足湍流子数组，则左右指针同时后移
			if arr[left] == arr[left+1] {
				left++
			}
			// 不然只需后移右指针
			right++
		} else {
			// 满足湍流子数组则右指针右移扩大窗口
			if arr[right-1] < arr[right] && arr[right] > arr[right+1] {
				right++
			} else if arr[right-1] > arr[right] && arr[right] < arr[right+1] {
				right++
			} else {
				// 不然则左指针移到右指针位置重置窗口
				left = right
			}
		}
		// 更新最大湍流子数组长度
		res = max(res, right-left+1)
	}
	return res
}

// 辅助函数
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

