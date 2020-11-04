/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
    //和第五十四题螺旋矩阵一样的思路
public:
    vector<vector<int>> generateMatrix(int n)
    {
        //用于返回的vector，它是一个n*n的矩阵
        vector<vector<int>> res(n, vector<int>(n, 0));
        //特殊情况
        if (n == 0)
            return res;
        //和第五十四题螺旋矩阵一样的思路
        int num = 1;
        int left = 0, right = n - 1;
        int up = 0, down = n - 1;
        //边界大小决定是否循环
        while (left <= right && up <= down)
        {
            //从左往右填
            for (int i = left; i <= right; i++)
            {
                res[up][i] = num++;
            }
            //一行填完更新上边界
            up++;
            //边界在判断一下
            if (up > down)
                break;
            //从上往下填
            for (int i = up; i <= down; i++)
            {
                res[i][right] = num++;
            }
            //一列填完更新右边界
            right--;
            //边界在判断一下
            if (right < left)
                break;
            //从右往左填
            for (int i = right; i >= left; i--)
            {
                res[down][i] = num++;
            }
            //一行填完更新下边界
            down--;
            //从下往上填
            for (int i = down; i >= up; i--)
            {
                res[i][left] = num++;
            }
            //一列填完更新左边界
            left++;
        }
        return res;
    }
};
// @lc code=end
