/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution
{
    // 所有的不被包围的O都直接或间接与边界上的O相连。我们可以利用这个性质判断O是否在边界上
    // 对于每一个边界上的O，我们以它为起点，标记所有与它直接或间接相连的字母O；
    // 最后我们遍历这个矩阵，对于每一个字母：
    // 如果该字母被标记过，则该字母为没有被字母X包围的字母O，我们将其还原为字母O；
    // 如果该字母没有被标记过，则该字母为被字母X包围的字母O，我们将其修改为字母X。
public:
    // 
    int n, m;
    // 深度优先遍历，我们可以使用深度优先搜索实现标记操作。
    // 把标记过的字母O修改为字母A
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O')
        {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        if (n == 0)
        {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++)
        {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end
