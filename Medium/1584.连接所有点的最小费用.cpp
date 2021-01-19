/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
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
    bool merge(int x, int y)
    {
        // 通过路径压缩的优化方法找到每个节点所在子集的代表
        int rootx = find(x);
        int rooty = find(y);
        // 在同一个子集就不需要合并
        if (rootx == rooty)
            return false;
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
        return true;
    }
};

struct Edge
{
    int length;
    int start;
    int end;
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int res = 0, num = 1;
        int n = points.size();
        Djset ds(n);
        vector<Edge> edges;
        // 创建边集
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Edge edge = {abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]), i, j};
                edges.push_back(edge);
            }
        }
        // 按照边的长度从小到大进行排序
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
            return a.length < b.length;
        });
        // Kruskal创建最小生成树，每次选择最小长度的边，每加入一条边，判断是否会造成回路
        for (auto &[len, x, y] : edges)
        {
            if (ds.merge(x, y))
            {
                res += len;
                num++;
                if (num == n)
                    break;
            }
        }
        return res;
    }
};
// @lc code=end
