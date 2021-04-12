/*
 * @lc app=leetcode.cn id=179 lang=golang
 *
 * [179] 最大数
 */

// @lc code=start
// 先将每组数字转换成字符串，再两两字符串拼接之后进行比较，然后就可以确定每两个字符串之间的相对位置了
func largestNumber(nums []int) string {
	// 特殊情况
	if nums == nil || len(nums) == 0 {
		return ""
	}
	var buffer bytes.Buffer
	strs := make([]string, len(nums))
	// 将每个数字都转换成字符串
	for i := range nums {
		strs[i] = strconv.Itoa(nums[i])
	}
	// 对字符串进行两两拼接之后比较大小
	sort.Slice(strs, func(i, j int) bool {
		s12 := strs[i] + strs[j]
		s21 := strs[j] + strs[i]
		return s12 > s21
	})
	// 最高位是0的话，那么整个数字都是0，直接返回0即可
	if strs[0] == "0" {
		return "0"
	}
	// 把数组中的字符串依次拼接起来
	for i := range strs {
		buffer.WriteString(strs[i])
	}
	return buffer.String()
}

// @lc code=end

