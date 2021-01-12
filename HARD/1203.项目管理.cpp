/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 */

// @lc code=start
class Solution
{
public:
    // 拓扑排序
    // deg是每个顶点的入度数目，graph[i]存储的是与顶点i出去到达的所有顶点，items存放的是当前待拓扑排序的点集
    vector<int> topSort(vector<int> &deg, vector<vector<int>> &graph, vector<int> &items)
    {
        queue<int> Q;
        vector<int> res;
        // 将所有初始入度为0的顶点都入队
        for (auto &item : items)
        {
            if (deg[item] == 0)
                Q.push(item);
        }
        // 队不空时循环
        while (!Q.empty())
        {
            // 出队
            int u = Q.front();
            Q.pop();
            res.emplace_back(u);
            // 去掉与该点相连的边后入度为0的顶点入队
            for (auto &v : graph[u])
            {
                if (--deg[v] == 0)
                    Q.push(v);
            }
        }
        // 存在拓扑排序则返回结果否则返回空数组
        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        vector<vector<int>> groupItem(n + m);

        // 组间和组内依赖图
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // 组间和组内入度数组
        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);

        vector<int> id;
        for (int i = 0; i < n + m; ++i)
        {
            id.emplace_back(i);
        }

        int leftId = m;
        // 给未分配的item(也就是题意中的-1)单独分配一个groupId(从m开始，防止冲突)
        for (int i = 0; i < n; ++i)
        {
            if (group[i] == -1)
            {
                group[i] = leftId;
                leftId += 1;
            }
            // 每一个group待拓扑排序的点集
            groupItem[group[i]].emplace_back(i);
        }
        // 依赖关系建图
        for (int i = 0; i < n; ++i)
        {
            int curGroupId = group[i];
            // beforeItems[i]存储的是在i任务之前需要完成的任务
            for (auto &item : beforeItems[i])
            {
                // 如果属于同一组，那么i的入度就要加1，并且组内该两顶点之间要添加一条边
                // 不属于同一组则组间的入度要加1，并且组间该两组之间要添加一条边
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId)
                {
                    itemDegree[i] += 1;
                    itemGraph[item].emplace_back(i);
                }
                else
                {
                    groupDegree[curGroupId] += 1;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        // 组间拓扑关系排序
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        // 若组间拓扑排序返回空数组
        if (groupTopSort.size() == 0)
        {
            return vector<int>{};
        }
        vector<int> ans;
        // 组内拓扑关系排序
        for (auto &curGroupId : groupTopSort)
        {
            int size = groupItem[curGroupId].size();
            if (size == 0)
            {
                continue;
            }
            vector<int> res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0)
            {
                return vector<int>{};
            }
            for (auto &item : res)
            {
                ans.emplace_back(item);
            }
        }
        return ans;
    }
};
// @lc code=end
