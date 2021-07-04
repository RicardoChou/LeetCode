/*
 * @lc app=leetcode.cn id=645 lang=golang
 *
 * [645] 错误的集合
 */
Î
// @lc code=start
func findErrorNums(nums []int) []int {
	numsMap := make(map[int]bool)
	res := make([]int, 2)
	for _, num := range nums {
		if numsMap[num] {
			res[0] = num
		}
		numsMap[num] = true
	}
	for i := 1; i <= len(nums); i++ {
		if !numsMap[i] {
			res[1] = i
			break
		}
	}
	return res
}
// @lc code=end

