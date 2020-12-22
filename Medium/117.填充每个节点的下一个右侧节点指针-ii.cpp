/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        //根节点加入队列
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            //记录当前层队列大小
            int size = q.size();
            //遍历这一层的所有节点
            for (int i = 0; i < size; i++)
            {
                //从队首取出元素
                Node *node = q.front();
                q.pop();
                //连接
                if (i < size - 1)
                {
                    node->next = q.front();
                }
                //将下一层节点加入队列
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        //返回根节点
        return root;
    }
};
// @lc code=end
