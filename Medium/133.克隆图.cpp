/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    // 深度优先遍历建图
public:
    // 题目节点数不超过100，可以不用map，直接用数组，降低空间开销
    Node *cloned[101];
    Node *cloneGraph(Node *node)
    {
        // 如果是空指针，则返回空
        if (!node)
            return node;
        // 该节点已经拷贝，直接返回该节点的指针即可
        if (cloned[node->val])
            return cloned[node->val];
        // 创建拷贝节点
        Node *p = new Node(node->val);
        //  递归会遍历每一个原有节点，然后将拷贝后的指针放入used
        cloned[node->val] = p;
        vector<Node *> tp = node->neighbors;
        //  将该节点的邻接节点放入拷贝节点邻接数组
        for (int i = 0; i < tp.size(); i++)
            // 递归实现每一个节点的更新
            p->neighbors.push_back(cloneGraph(tp[i]));
        // 返回拷贝后的节点
        return p;
    }
};
// @lc code=end
