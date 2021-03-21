/*
 * @lc app=leetcode.cn id=76 lang=golang
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
// 滑动窗口
func minWindow(s string, t string) string {
	// ori是存储t字符串中出现的字符与其对应的个数
	// cnt是存储滑动窗口中出现的字符与其对应的个数
	ori, cnt := map[byte]int{}, map[byte]int{}
	// 存储t字符串中出现的字符与其对应的个数
	for i := 0; i < len(t); i++ {
		ori[t[i]]++
	}
	// check函数用来判断当前s字符串的滑动窗口内的字符是否满足t字符串的符号与其个数的要求
	check := func() bool {
		for k, v := range ori {
			// 如果某个字符的个数比t中那个字符的少的话也不满足条件
			if cnt[k] < v {
				return false
			}
		}
		return true
	}
	// len用来保存最小长度，resL和resR保存滑动窗口的端点
	sLen, len, resL, resR := len(s), math.MaxInt32, -1, -1
	// 右端点右移来找到满足条件的的滑动窗口，左端点左移来找到最小的满足条件的滑动窗口
	for left, right := 0, 0; right < sLen; right++ {
		if right < sLen && ori[s[right]] > 0 {
			cnt[s[right]]++
		}
		// 左端点左移来找到最小的满足条件的滑动窗口
		for check() && left <= right {
			// 更新最小滑动窗口大小和相应的端点
			if right-left+1 < len {
				len = right - left + 1
				resL, resR = left, left+len
			}
			if _, ok := ori[s[left]]; ok {
				cnt[s[left]] -= 1
			}
			left++
		}
	}
	if resL == -1 {
		return ""
	}
	return s[resL:resR]
}

// @lc code=end

