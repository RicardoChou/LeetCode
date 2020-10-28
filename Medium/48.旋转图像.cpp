/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
    //先将矩阵转置再将每一行进行翻转
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int length = matrix.size();
        int temp;
        //先将矩阵转置(主要是注意循环的条件)
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j < length; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //将每一行进行翻转
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length / 2; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][length - j - 1];
                matrix[i][length - j - 1] = temp;
            }
        }
    }
};
// @lc code=end
