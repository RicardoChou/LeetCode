/*
 * @lc app=leetcode.cn id=992 lang=golang
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
func subarraysWithKDistinct(A []int, K int) int {
	if len(A) == 0 || K > len(A) {
		return 0
	}
	// hashMap := make(map[int]int, len(A)+1)
	// 用切片性能高很多
	hashMap := make([]int, len(A)+1)
	step, l, r, res := 0, 0, 0, 0
	count := 0
	for ; r < len(A); r++ {
		hashMap[A[r]]++
		// 该数字第一次出现
		if hashMap[A[r]] == 1 {
			count++
		}
		// 在左下标的数非唯一，或者超过K时，移动左下标
		for hashMap[A[l]] > 1 || count > K {
			if count > K {
				// 左边界指针后移
				hashMap[A[l]]--
				count--
				l++
				//有新数进来，之前的步数清0
				step = 0
			} else {
				hashMap[A[l]]--
				l++
				//step累计了之前移动的步数
				step++
			}
		}
		if count == K {
			res += step + 1
		}
	}
	return res
}

// @lc code=end

