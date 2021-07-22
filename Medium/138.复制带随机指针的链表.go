/*
 * @lc app=leetcode.cn id=138 lang=golang
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

// 先按照顺序复制生成一个链表，再用一个map来保存原来节点和新对应的节点
// 再重新复制random关系
func copyRandomList(head *Node) *Node {
	// 生成新的头节点
	res := new(Node)
	cur := head
	p := res
	//用一个map来保存原来节点和新生成节点的对应关系
	m := map[*Node]*Node{}
	for cur != nil {
		// 复制他们的节点信息
		p.Next = &Node{Val: cur.Val}
		//保存原来节点和新生成节点的对应关系
		m[cur] = p.Next
		p = p.Next
		cur = cur.Next
	}
	// 重新回到头节点处开始复制random信息
	cur = head
	p = res.Next
	for cur != nil {
		p.Random = m[cur.Random]
		cur = cur.Next
		p = p.Next
	}
	return res.Next
}

// @lc code=end

