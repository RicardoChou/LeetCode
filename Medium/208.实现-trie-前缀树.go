/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
// 用一个指针数组来表示子节点
// 用一个bool变量来表示是否到达底部
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	node := this
	for _, ch := range word {
		ch -= 'a'

		//子节点不存在。创建一个新的子节点，记录在children数组的对应位置上，然后沿着指针移动到子节点，继续搜索下一个字符。
		if node.children[ch] == nil {
			node.children[ch] = &Trie{}
		}
		//子节点存在则直接移动到子节点
		node = node.children[ch]
	}
	//插入完成则将isEnd置为true
	node.isEnd = true
}

func (this *Trie) SearchPrefix(prefix string) *Trie {
	node := this
	for _, ch := range prefix {
		ch -= 'a'
		// 如果不存在该字符则没有前缀，直接返回nil
		if node.children[ch] == nil {
			return nil
		}
		node = node.children[ch]
	}
	return node
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	node := this.SearchPrefix(word)
	return node != nil && node.isEnd

}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	return this.SearchPrefix(prefix) != nil
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end

