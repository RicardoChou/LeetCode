/*
 * @lc app=leetcode.cn id=331 lang=golang
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
// 用一个变量num表示还可以挂载元素的个数
// 遇到一个#即空节点则num--（因为一个空节点是不能提供挂载点的，但它本身会消耗一个挂载点），遇到一个数字则num++
// 因为遇到一个数字时，数字本身需要用掉一个挂载点，而每一个数字又可以带来两个挂载点
// 所以相当于每个数字增加了一个挂载点
// 如果遍历过程中num==0则返回false（因为如果是遍历过程中，说明后续不管是空节点还是数字节点，它至少需要一个挂载点）
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

