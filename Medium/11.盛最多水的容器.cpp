/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int temp = 0, res = 0, i = 0, j = height.size() - 1;
        while (i < j)
        {
            //选择两高度中较矮的那个作为最终的高度
            temp = (height[j] >= height[i] ? height[i] : height[j]) * (j - i);
            //更新最大值
            res = max(temp, res);
            //留下高的那条边，另一条边进行移动
            height[i] >= height[j] ? j-- : i++;
        }
        return res;
    }
};
// @lc code=end
