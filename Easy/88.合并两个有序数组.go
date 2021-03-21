/*
 * @lc app=leetcode.cn id=88 lang=golang
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
// 从后往前从大到小填充，可以防止数据丢失
func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		return
	}
	if m == 0 {
		copy(nums1, nums2)
		return
	}
	index := m + n - 1
	for p1, p2 := m-1, n-1; p1 >= 0 || p2 >= 0; index-- {
		if p1 == -1 {
			nums1[index] = nums2[p2]
			p2--
		} else if p2 == -1 {
			nums1[index] = nums1[p1]
			p1--
		} else if nums1[p1] >= nums2[p2] {
			nums1[index] = nums1[p1]
			p1--
		} else {
			nums1[index] = nums2[p2]
			p2--
		}
	}
	return
}

// @lc code=end

