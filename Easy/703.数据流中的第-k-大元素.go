/*
 * @lc app=leetcode.cn id=703 lang=golang
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start

type KthLargest struct {
	// 堆的容量，不包括数组第一个元素
	size int
	data []int
	// 当前元素数量
	count int
}

func Constructor(k int, nums []int) KthLargest {
	kth := KthLargest{}
	kth.size = k
	kth.data = []int{0}
	for _, num := range nums {
		kth.Add(num)
	}
	return kth
}

func (this *KthLargest) Add(val int) int {
	if this.count < this.size-1 {
		this.data = append(this.data, val)
		this.count += 1
	} else if this.count+1 == this.size {
		this.data = append(this.data, val)
		this.count += 1
		// 第一次填满k个数，使堆有序，后续Add只需在data[1]覆盖放入新值
		// data的最大下标
		n := len(this.data) - 1
		for i := n / 2; i >= 1; i-- {
			heapify(this.data, i)
		}
	} else {
		// 如果新元素大于堆中第k大的元素，说明目前的堆顶不是第k大，直接用新元素替换堆顶
		if val > this.data[1] {
			this.data[1] = val
			heapify(this.data, 1)
		}
	}
	return this.data[1]
}

// 构建小根堆
func heapify(a []int, i int) {
	n := len(a) - 1
	for {
		minPos := i
		if i*2 <= n && a[i*2] < a[minPos] {
			minPos = i * 2
		}
		if i*2+1 <= n && a[i*2+1] < a[minPos] {
			minPos = i*2 + 1
		}
		if minPos == i {
			break
		}
		a[minPos], a[i] = a[i], a[minPos]
		i = minPos
	}
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
// @lc code=end
