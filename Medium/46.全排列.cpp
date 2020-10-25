/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
    //使用回溯法
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtarck(res, nums, 0, nums.size());
        return res;
    }
    void backtarck(vector<vector<int>> &res, vector<int> &output, int cur, int length)
    {
        //所有数字都选完就将当前得到的数组插入到res中
        if (cur == length)
        {
            res.push_back(output);
            return;
        }
        for (int i = cur; i < length; i++)
        {
            //将题目给定的n个数的数组nums[]划分成左右两个部分，
            //左边的表示已经填过的数，右边表示待填的数，我们在递归搜索的时候要动态维护这个数组
            //这样做的目的是为了代替一个标记数组，因为如果是用标记数组的话，这样每次进行搜索的时候
            //将当前没有搜索过的那个数字进行填入，同时用标记数组标记它已经被填入，这样可以防止重复使用一个数字
            //然后每次递归跳出的时候都需要进行标记的取消，这是因为跳出递归说明当前查询已经结束，
            //需要重新从这个数字开始尝试填入，然后尝试其他的组合
            swap(output[i], output[cur]);
            //递归回溯
            backtarck(res, output, cur + 1, length);
            //跳出递归时撤销操作
            swap(output[i], output[cur]);
        }
    }
};
// @lc code=end
