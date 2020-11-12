/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
    //二分查找的变形，可以把整个二维数组看成是一个有序的一维数组
    //对应的一维虚数组的index与二维数组的行列关系是:
    //row = index / n ， col = index % n
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        //特殊情况
        if (matrix.empty())
            return false;
        //行数
        int row = matrix.size();
        //列数
        int column = matrix[0].size();
        //初始化二分查找的左右边界
        int left = 0, right = row * column - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int matrixMid = matrix[mid / column][mid % column];
            if (matrixMid == target)
                return true;
            else if (matrixMid < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
