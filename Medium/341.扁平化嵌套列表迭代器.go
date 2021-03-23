/*
 * @lc app=leetcode.cn id=341 lang=golang
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
	Stack []*NestedInteger // 栈是用来暂存元素的
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	stack := []*NestedInteger{}
	for i := len(nestedList) - 1; i >= 0; i-- { // 将元素从后开始一个个入栈
		stack = append(stack, nestedList[i]) // 从后是因为后进先出，位于前面的要先出
	}
	return &NestedIterator{Stack: stack} // 初始化并返回这个迭代器
}

func (this *NestedIterator) Next() int {
	this.stackTop2Integer()                     // 将栈顶元素转成integer
	top := this.Stack[len(this.Stack)-1]        // 获取栈顶
	this.Stack = this.Stack[:len(this.Stack)-1] // pop掉栈顶
	return top.GetInteger()                     // 返回integer
}

func (this *NestedIterator) HasNext() bool {
	this.stackTop2Integer()    // 将栈顶元素转成integer
	return len(this.Stack) > 0 // 如果stack没有空。说明能获取到integer
}

// 将栈顶元素变成integer（通过将list栈顶pop出来，再将它里面的元素一个个再放进去）
func (this *NestedIterator) stackTop2Integer() {
	for len(this.Stack) > 0 { // 直到栈空了
		top := this.Stack[len(this.Stack)-1] // 获取栈顶
		if top.IsInteger() {                 // 栈顶已经是integer，什么都不做
			return
		}
		this.Stack = this.Stack[:len(this.Stack)-1] // 栈顶是list，弹出栈顶
		list := top.GetList()                       // 获取list
		for i := len(list) - 1; i >= 0; i-- {       // 从后开始遍历list
			this.Stack = append(this.Stack, list[i]) // 将list的元素推入栈
		}
	}
}

// @lc code=end

