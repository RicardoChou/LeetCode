/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
public:
    //其实就是二叉树前序遍历线索化的过程
    //前序遍历是根、左、右
    //对于当前节点，如果其左子节点不为空，
    //则在其左子树中找到最右边的节点，作为前驱节点，
    //将当前节点的右子节点赋给前驱节点的右子节点，
    //然后将当前节点的左子节点赋给当前节点的右子节点，
    //并将当前节点的左子节点设为空。对当前节点处理结束后，
    //继续处理链表中的下一个节点，直到所有节点都处理结束。
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            //如果其左子节点不为空
            if (cur->left)
            {
                auto next = cur->left;
                auto predecessor = next;
                //在其左子树中找到最右边的节点，作为前驱节点
                while (predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                //当前节点的右子节点赋给前驱节点的右子节点
                predecessor->right = cur->right;
                //将当前节点的左子节点设为空
                cur->left = NULL;
                //将当前节点的左子节点赋给当前节点的右子节点
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end
