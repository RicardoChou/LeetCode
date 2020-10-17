/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
    //三个标志矩阵，分别记录各行，各列，各小方阵是否出现某个数字，
    //其中行和列标志下标很好对应，就是小方阵的下标需要稍稍转换一下
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        //三个标志矩阵，分别记录各行，各列，各小方阵是否出现某个数字
        int row[10][10] = {0};
        int col[10][10] = {0};
        int cell[10][10] = {0};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char &ch = board[i][j];
                if (ch == '.')
                    continue;
                int r1 = ++row[i][ch - '0'];
                int r2 = ++col[j][ch - '0'];
                //对小方阵进行一个转换
                int r3 = ++cell[i / 3 * 3 + j / 3][ch - '0'];
                if (r1 > 1 || r2 > 1 || r3 > 1)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
