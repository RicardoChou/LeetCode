/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x1, y1, x2, y2;
        // 防止溢出
        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            x1 = coordinates[i][0] - coordinates[i - 1][0];
            y1 = coordinates[i][1] - coordinates[i - 1][1];
            x2 = coordinates[i + 1][0] - coordinates[i][0];
            y2 = coordinates[i + 1][1] - coordinates[i][1];
            if (y1 * x2 != x1 * y2)
                return false;
        }
        return true;
    }
};
// @lc code=end
