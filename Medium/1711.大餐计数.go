/*
 * @lc app=leetcode.cn id=1711 lang=golang
 *
 * [1711] 大餐计数
 */

// @lc code=start
// 题目的边界条件：deliciousness[i]最大不会超过2的20次方，所以断定最终总和的有效幂次也不会超过2的21次方
const MOD = int(1e9 + 7)

func countPairs(deliciousness []int) int {
	res := 0
	table := make(map[int]int)
	for _, val := range deliciousness {
		sum := 1
		for i := 0; i <= 21; i++ {
			res += table[sum-val]
			sum <<= 1
		}
		table[val]++
	}
	return res % MOD
}

// @lc code=end

