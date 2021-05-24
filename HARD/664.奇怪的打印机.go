/*
 * @lc app=leetcode.cn id=664 lang=golang
 *
 * [664] 奇怪的打印机
 */

// @lc code=start
func strangePrinter(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	// 注意到f[i][j]的计算需要用到f[i][k]和f[k+1][j]（其中i≤k<j）。
	// 为了保证动态规划的计算过程满足无后效性，在实际代码中，我们需要改变动态规划的计算顺序，从大到小地枚举i，并从小到大地枚举j，
	// 这样可以保证当计算f[i][j]时，f[i][k]和f[k+1][j]都已经被计算过。
	for i := n - 1; i >= 0; i-- {
		// 边界条件，长度为1的字符串只需要打印一次
		f[i][i] = 1
		for j := i + 1; j < n; j++ {
			// 区间两端的字符相同，那么当我们打印左侧字符s[i]时，可以顺便打印右侧字符s[j]，
			// 这样我们即可忽略右侧字符对该区间的影响，只需要考虑如何尽快打印完区间[i,j-1]即可，即此时有f[i][j]=f[i][j-1]。
			if s[i] == s[j] {
				f[i][j] = f[i][j-1]
				// s[i]=s[j]，即区间两端的字符不同，那么我们需要分别完成该区间的左右两部分的打印。
				// 我们记两部分分别为区间[i,k]和区间[k+1,j]（其中i≤k<j），
				// 此时 f[i][j]就等于min(f[i][j], f[i][k]+f[k+1][j])
			} else {
				f[i][j] = math.MaxInt64
				for k := i; k < j; k++ {
					f[i][j] = min(f[i][j], f[i][k]+f[k+1][j])
				}
			}
		}
	}
	return f[0][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end

