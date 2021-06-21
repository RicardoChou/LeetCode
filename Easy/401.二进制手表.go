/*
 * @lc app=leetcode.cn id=401 lang=golang
 *
 * [401] 二进制手表
 */

// @lc code=start
// 双循环，i代表小时，j代表分钟，数一下i和j二进制形式中1的个数，如果和num一样，则为当前num可以表示的时间。
func readBinaryWatch(turnedOn int) []string {
	res := []string{}
	for i := 0; i < 12; i++ {
		for j := 0; j < 60; j++ {
			// 获取小时和分钟数的二进制形式
			b1 := fmt.Sprintf("%b", i)
			b2 := fmt.Sprintf("%b", j)
			// 计算小时和分钟的二进制形式中的1的个数
			num1 := strings.Count(b1, "1") + strings.Count(b2, "1")
			// 如果1的个数和turnedOn相同，那么就加入返回结果集中
			if num1 == turnedOn {
				res = append(res, fmt.Sprintf("%d:%02d", i, j))
			}
		}
	}
	return res
}

// @lc code=end

