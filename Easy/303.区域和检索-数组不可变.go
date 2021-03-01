/*
 * @lc app=leetcode.cn id=303 lang=golang
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
type NumArray struct {
	// sumArray存储的是前缀和
	sumArray []int
}

func Constructor(nums []int) NumArray {
	sumArray := make([]int, len(nums)+1)
	for index, v := range nums {
		sumArray[index+1] = sumArray[index] + v
	}
	return NumArray{sumArray}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.sumArray[j+1] - this.sumArray[i]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
// @lc code=end

