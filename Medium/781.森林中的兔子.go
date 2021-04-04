/*
 * @lc app=leetcode.cn id=781 lang=golang
 *
 * [781] 森林中的兔子
 */

// @lc code=start
// 贪心算法，让尽可能多的说同一个数字的兔子属于同一种颜色
func numRabbits(answers []int) int {
	// key是兔子说出的数字，value是该数字已经说过多少次
	dict := make(map[int]int)
	var res int
	for _, i := range answers {
		// 如果说该数字已经说过的次数比这个数字本身小，那么把这一次加进去也满足条件
		if dict[i] <= i {
			dict[i]++
			continue
		}
		// 如果该数字已经说过的次数比这个数字本身大，那再把这一次加进去就不满足条件
		// 这时候就需要将说这个数字的这一组兔子归为同一种颜色，并且将这个数字已经出现过的次数重置为1
		// 这样下次扫描到说出该数字的兔子就是另外一组来
		res += dict[i]
		dict[i] = 1
	}
	// 将剩余的同一组的兔子数量累加上去
	for k, v := range dict {
		if v == 0 {
			continue
		}
		// 记得要算上自己，所以需要加1
		res = res + k + 1
	}
	return res
}

// @lc code=end

