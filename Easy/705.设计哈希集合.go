/*
 * @lc app=leetcode.cn id=705 lang=golang
 *
 * [705] 设计哈希集合
 */

// @lc code=start
// 链地址法，先求出hash值，每个hash值用一个链表来链接不同的key值

// 用一个素数作为求hash值的基数
const base = 857

type MyHashSet struct {
	data []list.List
}

/** Initialize your data structure here. */
func Constructor() MyHashSet {
	return MyHashSet{make([]list.List, base)}
}

func (this *MyHashSet) hash(key int) int {
	return key % base
}

func (this *MyHashSet) Add(key int) {
	if !this.Contains(key) {
		h := this.hash(key)
		this.data[h].PushBack(key)
	}

}

func (this *MyHashSet) Remove(key int) {
	h := this.hash(key)
	for i := this.data[h].Front(); i != nil; i = i.Next() {
		if i.Value.(int) == key {
			this.data[h].Remove(i)
		}
	}
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	h := this.hash(key)
	for i := this.data[h].Front(); i != nil; i = i.Next() {
		if i.Value.(int) == key {
			return true
		}
	}
	return false
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
// @lc code=end

