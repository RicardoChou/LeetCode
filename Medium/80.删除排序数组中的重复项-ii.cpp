/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution
{
    //双指针遍历法
public:
    //快指针:遍历整个数组
    //慢指针:记录可以覆写数据的位置
    //规定每个元素最多出现两次，因此，应检查快指针指向的元素和慢指针指针所指向单元的前一个元素是否相等。
    //相等则不更新慢指针，只更新快指针；不相等时，先将慢指针后移一位，再将快指针指向的元素覆写入慢指针指向的单元，
    //最后更新快指针。

    int removeDuplicates(vector<int> &nums)
    {
        //nums数组总共不超过两个元素，则直接返回即可
        if (nums.size() <= 2)
            return nums.size();
        //因为fast指针指向的元素是与slow指针指向元素的前一个元素进行比较的，所以slow初始化为1
        int slow = 1;
        //fast指针用于遍历整个数组
        for (int fast = 2; fast < nums.size(); fast++)
        {
            //检查快指针指向的元素和慢指针指针所指向单元的前一个元素是否相等。
            //不相等时，先将慢指针后移一位，再将快指针指向的元素覆写入慢指针指向的单元
            if (nums[fast] != nums[slow - 1])
            {
                nums[++slow] = nums[fast];
            }
            //相等则不更新慢指针，只更新快指针（快指针通过循环每次都会更新
        }
        //返回新数组的长度
        return slow + 1;
    }
};
// @lc code=end
