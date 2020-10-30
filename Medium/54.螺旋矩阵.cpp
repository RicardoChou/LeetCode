/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
    //从左至右再从上至下再从右至左再从下至上不断循环，退出循环的条件是到达边界
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        //特情：数组为空直接返回
        if (matrix.empty())
            return res;
        //初始化四个边界
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (true)
        {
            //从左遍历至最右
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            //重新设置上边界，如果上边界大于下边界，就退出循环
            if (++top > bottom)
                break;
            //从上遍历至最下
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            //重新设置右边界，如果右边界小于左边界，就退出循环
            if (--right < left)
                break;
            //从右遍历至最左
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            //重新设置下边界，如果下边界小于上边界，就退出循环
            if (--bottom < top)
                break;
            //从下遍历至最上
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            //重新设置左边界，如果左边界大于右边界，就退出循环
            if (++left > right)
                break;
        }
        return res;
    }
};
// @lc code=end
