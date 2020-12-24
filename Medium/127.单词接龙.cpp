/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
    // 建图再广度优先遍历
public:
    // map存储word和对应的id
    unordered_map<string, int> wordId;
    // 边表
    vector<vector<int>> edge;
    int nodeNum = 0;
    // 添加单词
    void addWord(string &word)
    {
        // 没出现过的单词就添加到map中
        if (!wordId.count(word))
        {
            // 给每个单词分配不同的id
            wordId[word] = nodeNum++;
            // 生成一条没有顶点的空边
            edge.emplace_back();
        }
    }
    // 添加边
    void addEdge(string &word)
    {
        addWord(word);
        // 获取word的id
        int id1 = wordId[word];
        // 给每一个单词的某个字符替换成*，创建每一个后继的虚节点
        // 让该单词与每一个虚节点连接一条边
        // 因为用了&取地址符，所以it的改变会导致原单词的改变
        for (char &it : word)
        {
            // 暂存原来的字符
            char temp = it;
            // 给每一个单词的某个字符替换成*，创建每一个后继的虚节点
            it = '*';
            // 创建虚节点
            addWord(word);
            int id2 = wordId[word];
            // 建立该单词与每一个虚节点的边
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            // 将单词还原
            it = temp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 创建字典中每一个单词和对应的边
        for (string &word : wordList)
        {
            addEdge(word);
        }
        // 题设中beginWord不在字典中，所以需要单独建立它的map和边
        addEdge(beginWord);
        // 特殊情况:如果endWord不在字典中，则肯定无法进行转换
        if (!wordId.count(endWord))
        {
            return 0;
        }
        // 广度优先遍历的距离
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;
        // 广度优先遍历用队列
        queue<int> que;
        // beginId入队
        que.push(beginId);
        // 队不空时循环
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            // 找到endWord时
            if (x == endId)
                // 得到的距离为实际最短路径长度的两倍。
                // 同时我们并未计算起点对答案的贡献，所以我们应当返回距离的一半再加一的结果。
                return dis[endId] / 2 + 1;
            // 更新dis
            for (int &it : edge[x])
            {
                if (dis[it] == INT_MAX)
                {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};
// @lc code=end
