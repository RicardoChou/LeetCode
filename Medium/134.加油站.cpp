/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 当考虑i能到达的最远的时候，假设是j。
        // 假设i+1的节点能绕一圈，那么就意味着从i+1开始一定能到达j+1。
        // 又因为从i能到达i+1，所以从i也能到达j+1。
        // 但事实上，i最远到达j。产生矛盾，所以i+1的节点一定不能绕一圈。
        // 所以下一次的i我们不需要从i+1开始考虑，直接从j+1开始考虑即可。

        // 还有一种情况，就是因为到达末尾的时候，会回到0。
        // 如果i最远能够到达j，根据上边的结论i+1到j之间的节点都不可能绕一圈了。
        // 想象成一个圆，所以i后边的节点就都不需要考虑了，直接返回-1即可。

        int n = gas.size();
        // 扫描每一个点，将该点作为起点看能否最终回到该点
        for (int i = 0; i < n; i++)
        {
            int j = i;
            // 初始剩余油量就是起点的gas量
            int remain = gas[j];
            // 能够驶到下一个加油站
            while (remain - cost[j] >= 0)
            {
                // 更新剩余油量
                remain = remain - cost[j] + gas[(j + 1) % n];
                // 到达下一个加油站
                j = (j + 1) % n;
                // 回到原点说明该起点可以完成回路
                if (j == i)
                    return i;
            }
            //最远距离绕到了之前，所以i后边的都不可能绕一圈了
            if (j < i)
            {
                return -1;
            }
            //i直接跳到j，外层for循环执行i++，相当于从j+1开始考虑
            i = j;
        }
        // 不能则返回-1
        return -1;
    }
};
// @lc code=end
