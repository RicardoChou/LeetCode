/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start

// 并查集的通用模板
class Djset
{
public:
    // 用于记录该节点的父节点，所有父节点相同的节点位于同一连通图
    vector<int> parent;
    // 节点的秩，主要记录该节点目前位于的树的深度，从子节点出发
    // 主要用于优化，在合并两个父节点时，通过rank的大小判断谁父谁子
    // 称为“按秩合并”，即总是将更小的树连接至更大的树上。
    // 因为影响运行时间的是树的深度，更小的树添加到更深的树的根上将不会增加秩除非它们的秩相同。
    // 单元素的树的秩定义为0，当两棵秩同为r的树联合时，它们的秩为r+1。
    vector<int> rank;
    // 初始化Djset
    Djset(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // 初始化为单元素，每个元素的parent就是自身
            parent.push_back(i);
            // 单元素的树的秩初始化定义为0
            rank.push_back(0);
        }
    }
    // 优化查找每个节点所在的子集的代表(也就是根)的方法，称为“路径压缩”
    // 是一种在执行“查找”时扁平化树结构的方法。
    // 关键在于在路径上的每个节点都可以直接连接到根上；他们都有同样的表示方法。
    // 为了达到这样的效果，Find递归地经过树，改变每一个节点的引用到根节点。
    // 得到的树将更加扁平，为以后直接或者间接引用节点的操作加速。
    int find(int x)
    {
        // 如果该节点不是最终所在子集代表的话，就递归找到它的最终父节点(代表)，
        // 并最终将其的父节点直接指向根节点
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // 合并两个节点
    // 如果处于同一个并查集，不需要合并
    // 如果不处于同一个并查集，判断两个rootx和rooty谁的秩大
    void merge(int x, int y)
    {
        // 通过路径压缩的优化方法找到每个节点所在子集的代表
        int rootx = find(x);
        int rooty = find(y);
        // 如果不是同一个子集就需要合并
        if (rootx != rooty)
        {
            // 将秩小的子集接入到秩大的子集中去
            if (rank[rootx] < rank[rooty])
                parent[rootx] = rooty;
            else if (rank[rooty] < rank[rootx])
                parent[rooty] = rootx;
            // 当两棵秩同为r的树联合时，它们的秩为r+1
            else
            {
                parent[rooty] = rootx;
                rank[rootx] += 1;
            }
        }
    }
};
class Solution
{
    // 使用并查集方法：对于pairs中的可以间接相连的pair，合成同一个并查集
    // 比如果[0,1],[0,2]，那0，2，3都可以间接相连作为同一个并查集
    // 然后就是通过该方法构建并查集，再通过并查集构建图
    // 遍历所有非连通图
    // 针对同一个联通图中的节点，对该图中的所有元素按字典序排序
    // 将排序好的元素依次插入到结果中
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        // 并查集
        // 查找所有可交换位置的集合,排序每个集合内的字符,再查回原字符串
        // 集合放入哈希表 - key为集合root，value为该root下的集合元素
        unordered_map<int, set<int>> mymap;
        int n = s.length();
        // 构建并查集
        Djset ds(n);
        for (auto &p : pairs)
        {
            // 对于每一个pair进行并查集的合并
            ds.merge(p[0], p[1]);
        }
        // 集合放入哈希表 - 键为集合root，键值为root下的集合元素
        for (int i = 0; i < n; i++)
            mymap[ds.find(i)].insert(i);

        for (auto &t : mymap)
        {
            string str;
            // 提取集合里每个位置的字母
            for (auto &c : t.second)
                str += s[c];
            // 排序后依次放回 - set内位置坐标自身有序，这样可以获得字典序最小的字符串
            sort(str.begin(), str.end());
            int cnt = 0;
            for (auto &c : t.second)
                s[c] = str[cnt++];
        }
        return s;
    }
};
// @lc code=end
