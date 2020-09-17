/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
    /*这题提供的是无序的数组，返回也可以是无序的数组
      所以可以用双指针法，一个头指针从前向后移动。
      一个尾指针从后向前移动，这样就只需要一次扫描，如果两次扫描则会超时
    */
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        //尾指针
        int j = len - 1;
        //变量k是用来记录数组中等于val的数字的个数
        int k = 0;
        //头指针，进行一边扫描
        for (int i = 0; i <= j; i++)
        {
            //如果头指针扫描的数字等于val，则需要移动尾指针
            if (nums[i] == val)
            {
                //等于val的个数+1
                k++;
                //如果尾指针扫描的数字也等于val，且头尾指针还没相遇
                while (nums[j] == val && j > i)
                {
                    //等于val的个数+1
                    k++;
                    //尾指针前移
                    j--;
                }
                //将尾指针扫描到的不等于val的数字与头指针扫描到等于val数字进行交换
                nums[i] = nums[j--];
            }
        }
        //数组总长度减去等于val的数字的长度，且执行完后等于val的数字均在数组尾部
        return len - k;
    }
};
// @lc code=end
