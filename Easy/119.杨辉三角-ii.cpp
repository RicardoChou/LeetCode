/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        //第K行的vector大小为 rowIndex+1
        vector<int> kRows(rowIndex + 1);
        //利用前一行求后一行，第K行要循环K遍
        for (int i = 0; i <= rowIndex; i++)
        {
            //行末尾为1
            kRows[i] = 1;
            //每一行的更新过程
            for (int j = i; j > 1; j--)
            {
                //因为是从后往前更新，所以kRows[j-2]已经是更新完的当前行的数
                //而等号右边kRows[j-1]是上一行遗留的数，用这两个数来进行更新
                kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
            }
        }
        return kRows;
    }
};
// @lc code=end
