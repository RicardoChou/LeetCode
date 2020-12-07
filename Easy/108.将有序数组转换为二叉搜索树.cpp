/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    //给定一个升序序列，求对应的平衡二叉树
    //每次选择中间那个数作为根节点，再递归生成左右子树
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return subFunction(nums, 0, nums.size() - 1);
    }
    //辅助函数
    TreeNode *subFunction(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        //每次选择中间的数作为根节点
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        //递归生成左右子树
        root->left = subFunction(nums, left, mid - 1);
        root->right = subFunction(nums, mid + 1, right);
        //返回根节点
        return root;
    }
};
// @lc code=end
