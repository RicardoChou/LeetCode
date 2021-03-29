/*
 * @lc app=leetcode.cn id=338 lang=golang
 *
 * [338] 比特位计数
 */

// @lc code=start
func countBits(num int) []int {
	var temp int
	var res []int
	for i := 0; i <= num; i++ {
		temp = countNum(i)
		res = append(res, temp)
	}
	return res
}

// 计算每个数转换成二进制中1的个数
// 对于任意整数x，令x=x&(x−1)，该运算将x的二进制表示的最后一个1变成0。
// 因此，对x重复该操作，直到x变成0，则操作次数即为x的「一比特数」。

func countNum(x int) (res int) {
	for ; x > 0; x &= x - 1 {
		res++
	}
	return
}

// @lc code=end

