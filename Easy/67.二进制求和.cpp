/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
    //二进制加法，本质上是与十进制加法类似的，只不过由遇十进一变成了遇二进一
public:
    string addBinary(string a, string b)
    {
        string res = "";
        /*设置一个进位carry，初值是0
    我们可以用两个指针分别从两个字符串的末尾开始向高位遍历
    */
        int i = a.size() - 1, j = b.size() - 1, carry = 0, m, n;
        //循环直至到达某个字符串扫描完
        while (i >= 0 || j >= 0)
        {
            /*如果两个字符串长度是不一致的，那么我们需要对较短的字符串前面补0
        由于二进制的特点，高位补0是不影响二进制的值的，所以如果字符串可以取出值
        就将字符取出再减去'0'得到int值，如果不能取出值，就直接赋0进行运算
        */
            int m = i >= 0 ? a[i--] - '0' : 0;
            int n = j >= 0 ? b[j--] - '0' : 0;
            //将三者相加
            int sum = m + n + carry;
            //得到的和对二取余的值转换成字符串再加到结果字符串中
            res = to_string(sum % 2) + res;
            //对二进行除法的值赋给进位carry。
            carry = sum / 2;
        }
        // 如果在循环结束后carry是1，则需要在最高位增加一个1，即在结果字符串首部加1。
        return carry == 1 ? "1" + res : res;
    }
};
// @lc code=end
