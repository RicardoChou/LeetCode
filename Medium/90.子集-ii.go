/*
 * @lc app=leetcode.cn id=90 lang=golang
 *
 * [90] 子集 II
 */

// @lc code=start

// 考虑数组[1,2,2]，选择前两个数，或者第一、三个数，都会得到相同的子集。

// 也就是说，对于当前选择的数x，若前面有与其相同的数y，且没有选择y，此时包含x的子集，必然会出现在包含y的所有子集中。

// 我们可以通过判断这种情况，来避免生成重复的子集。代码实现时，可以先将数组排序；

// 迭代时，若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。

var res [][]int

func subsetsWithDup(nums []int) [][]int {
	res = make([][]int, 0)
	// 排序可以保证重复数字在一起
	sort.Ints(nums)
	dfs([]int{}, nums, 0)
	return res
}

//
func dfs(temp, nums []int, start int) {
	tmp := make([]int, len(temp))
	copy(tmp, temp)
	res = append(res, tmp)
	for i := start; i < len(nums); i++ {
		// 若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。
		// 但是如果上一个数字选择了，那么就不会导致重复，则当前数字是可以选择的
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		// 数字加入
		temp = append(temp, nums[i])
		// 递归dfs
		dfs(temp, nums, i+1)
		temp = temp[:len(temp)-1]
	}
}

// @lc code=end

