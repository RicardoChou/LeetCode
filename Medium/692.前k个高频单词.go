/*
 * @lc app=leetcode.cn id=692 lang=golang
 *
 * [692] 前K个高频单词
 */

// @lc code=start
// map记录每个单词出现的频率，再根据单词出现的频率和每个单词的字典序进行排序
func topKFrequent(words []string, k int) []string {
	// map记录每个单词出现的频率
	temp := map[string]int{}
	for _, word := range words {
		temp[word]++
	}
	// resString存储每个单词
	resString := make([]string, 0, len(temp))
	for word := range temp {
		resString = append(resString, word)
	}
	// sort.Slice按照每个单词出现的频率和每个单词的字典序进行排序
	sort.Slice(resString, func(i, j int) bool {
		s, t := resString[i], resString[j]
		return temp[s] > temp[t] || temp[s] == temp[t] && s < t
	})
	return resString[:k]
}

// @lc code=end

