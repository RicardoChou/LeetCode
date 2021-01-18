/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
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
        for (int i = 0; i <= n; i++)
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string>> res;
        // 存储每个邮箱属于哪个账户 ，同时在遍历邮箱时判断邮箱是否出现过
        // <邮箱，账户id>
        unordered_map<string, int> um;
        int n = accounts.size();
        Djset ds(n);
        // 判断邮箱是否出现过并且若出现过则合并两个连通图
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                string s = accounts[i][j];
                // 若该邮箱没有出现过，则存储该邮箱属于哪一个账户
                if (um.find(s) == um.end())
                {
                    um[s] = i;
                }
                // 该邮箱出现过，则合并
                else
                {
                    ds.merge(i, um[s]);
                }
            }
        }
        // 存储每个账户下的邮箱用于最终返回结果
        // <账户id, 邮箱列表>
        // 这里的key必须是账户id，不能是账户名称，名称可能相同，会造成覆盖
        unordered_map<int, vector<string>> umv;
        for (auto &[k, v] : um)
            umv[ds.find(v)].emplace_back(k);
        // 输出每一个用户最终返回结果
        for (auto &[k, v] : umv)
        {
            sort(v.begin(), v.end());
            vector<string> tmp(1, accounts[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end
