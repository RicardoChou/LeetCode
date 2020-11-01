/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
    //贪心算法:用一个变量指示右边界，在右边界变量左边的数都是可以到达的位置
    //如果当前位置加上当前的数大于右边界变量，那就更新右边界变量
    //当右边界变量大于整个数组的右边界时，返回true，最后达不到得话，返回false
public:
    bool canJump(vector<int> &nums)
    {
        //用一个变量指示右边界
        int rightEdge = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            //首先得保证当前这个数是能达到的，也就是这个数是在右边界变量的左边
            if (i <= rightEdge)
            {
                //更新右边界变量
                if (rightEdge < i + nums[i])
                    rightEdge = i + nums[i];
            }
            //当右边界变量大于整个数组的右边界时，返回true，最后达不到得话，返回false
            if (rightEdge >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
