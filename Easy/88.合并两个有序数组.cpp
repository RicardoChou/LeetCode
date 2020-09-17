/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            //从后往前按照降序的方法插入元素，这样从前往后就是升序了
            if (nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        //如果nums2还有升序元素的话，就把剩下的元素全部赋上去
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};
// @lc code=end
