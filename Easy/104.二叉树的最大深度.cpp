/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    //广度优先搜索遍历非递归算法
    //把每一层的节点都弹出高度才加一
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        //广度优先遍历用队列
        queue<TreeNode *> q;
        //根节点入队
        q.push(root);
        //初始高度设为1
        int ans = 0;
        //队不空
        while (!q.empty())
        {
            //将该层的所有节点都弹出，并将他们的所有的子节点都入队
            int size = q.size();
            while (size > 0)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                //每弹出一个节点记得size减一
                size -= 1;
            }
            //高度加一
            ans += 1;
        }
        return ans;
    }
};
// @lc code=end
