/*
 * @lc app=leetcode.cn id=331 lang=golang
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
// 用一个变量num表示还可以压入的元素的个数
// 遇到一个#即空节点则num--，遇到一个数字则num++
// 因为遇到一个数字时，数字本身需要用掉一个位置，而每一个数字又可以带来两个位置
// 所以相当于每个数字增加了一个位置
// 如果遍历过程中num==0则返回false
// 最终遍历完成式num==0则返回true，否则返回false
func isValidSerialization(preorder string) bool {
	n := len(preorder)
	// 初始预留一个位置
	num := 1
	for i := 0; i < n; {
		if num == 0 {
			return false
		} else if preorder[i] == ',' {
			i++
		} else if preorder[i] == '#' {
			num--
			i++
		} else {
			// 该循环是有可能数字不止一位数
			for i < n && preorder[i] != ',' {
				i++
			}
			num++
		}
	}
	return num == 0
}

// @lc code=end

