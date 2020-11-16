/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
    //深度优先遍历,用一个visited数组表示该字母是否访问过
    //如果该字母与给定word中对应的字母不同，直接返回false
    //如果相同，则递归比较其后面的子串
    //注意每次退出递归，要将visited数组对应位置重置为0（未访问过）
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = check(board, word, visited, i, j, 0);
                if (flag)
                {
                    return true;
                }
            }
        }
        return false;
    }

    //深度优先遍历辅助算法
    bool check(vector<vector<char>> &board, string &word, vector<vector<int>> &visited, int i, int j, int k)
    {
        //如果不相同，则直接返回false
        if (board[i][j] != word[k])
            return false;
        //如果全部都相同，返回true
        else if (k == word.size() - 1)
        {
            return true;
        }
        //将该位置visited标记未已访问
        visited[i][j] = true;
        //该vector是用于进行转向的模板，也就是用于遍历当前位置相邻的几个位置，相当于往上下左右都走一遍
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        //遍历递归该位置相邻的位置
        for (const auto &direction : directions)
        {
            //相当于往上下左右都走一遍
            int newi = i + direction.first, newj = j + direction.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if (!visited[newi][newj])
                {
                    //递归比较子串
                    bool flag = check(board, word, visited, newi, newj, k + 1);
                    //子串匹配成功则返回true
                    if (flag)
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
        //跳出递归记得重置已访问标记
        visited[i][j] = false;
        //匹配失败返回false
        return result;
    }
};
// @lc code=end
