/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        //两种特殊情况
        //1.如果是负数则不可能是回文数
        //2.如果能被10整除则不可能是回文数，0除外
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        /*上述特殊情况不满足则进行正常判断流程
        因为题设要求不将整数转为字符串进行比较，所以可以采取和Easy题中的整数反转一样，进行反转后与原数字进行比较
        但是这里原数字全部进行反转可能会超出int上限，所以我们只需要进行一半反转，这样原数字x也变成了一半
        反转后的res也变成了一半，可以将这两个数直接进行比较
        */
        int res = 0;
        //因为如果原数字x大于反转后res的话，说明反转还没有到一半，那么就可以继续反转
        while (x > res)
        {
            //反转的基本操作
            res = res * 10 + x % 10;
            x /= 10;
        }
        //因为while判断条件是x>res，所以跳出循环时x是小于等于res的。
        //所以有两种判断可能
        //1.x是等于res的，这说明它是回文数且数字的个数是偶数，正好反转一半
        //2.可能回文数的数字长度是奇数，这时候因为跳出循环的条件是x小于等于res，所以需要将res的最后一位去掉进行比较
        return res == x || x == res / 10;
    }
};
// @lc code=end
