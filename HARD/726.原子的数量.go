/*
 * @lc app=leetcode.cn id=726 lang=golang
 *
 * [726] 原子的数量
 */

// @lc code=start

//判断当前字符是否是数字的辅助函数
func isDigit(b byte) bool {
	return '0' <= b && b <= '9'
}

//判断当前字符是否是小写的辅助函数
func isLower(b byte) bool {
	return 'a' <= b && b <= 'z'
}

func countOfAtoms(s string) (res string) {
	stack := []map[string]int{{}}
	i, n := 0, len(s)
	// 获取每一个数字
	parseNumber := func() (v int) {
		if i == n || !isDigit(s[i]) {
			return 1
		}
		for ; i < n && isDigit(s[i]); i++ {
			v = v*10 + int(s[i]-'0')
		}
		return
	}
	for i < n {
		switch s[i] {
		case '(':
			stack = append(stack, map[string]int{})
			i++
		case ')':
			mp := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			i++
			v := parseNumber()
			for s, c := range mp {
				stack[len(stack)-1][s] += c * v
			}
		default:
			st := i
			for i++; i < n && isLower(s[i]); i++ {
			}
			name := s[st:i]
			stack[len(stack)-1][name] += parseNumber()
		}
	}
	mp := stack[0]
	ss := make([]string, 0, len(mp))
	for k := range mp {
		ss = append(ss, k)
	}
	sort.Strings(ss)
	for _, s := range ss {
		res += s
		if v := mp[s]; v > 1 {
			res += strconv.Itoa(v)
		}
	}
	return
}

// @lc code=end

