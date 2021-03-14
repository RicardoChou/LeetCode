/*
 * @lc app=leetcode.cn id=706 lang=golang
 *
 * [706] 设计哈希映射
 */

// @lc code=start

// 链表法解决冲突问题
const base = 857

type entry struct {
	key, value int
}

type MyHashMap struct {
	data []list.List
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
	return MyHashMap{make([]list.List, base)}
}

func (m *MyHashMap) hash(key int) int {
	return key % base
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if ee := e.Value.(entry); ee.key == key {
			e.Value = entry{key, value}
			return
		}
	}
	this.data[h].PushBack(entry{key, value})
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if ee := e.Value.(entry); ee.key == key {
			return ee.value
		}
	}
	return -1
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if ee := e.Value.(entry); ee.key == key {
			this.data[h].Remove(e)
		}
	}
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
// @lc code=end

