/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    //题设返回的是一个vector，所以最后return可以返回多个数字，会自动装载入vector中返回
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        unordered_map是一个将key和value关联起来的容器，它可以高效的根据单个key值查找对应的value。
        key值应该是唯一的，key和value的数据类型可以不相同。
        unordered_map存储元素时是没有顺序的，只是根据key的哈希值，将元素存在指定位置，
        所以根据key查找单个value时非常高效，平均可以在常数时间内完成。
        unordered_map查询单个key的时候效率比map高，但是要查询某一范围内的key值时比map效率低。
        可以使用[]操作符来访问key值对应的value值。
        */
        //声明一个unordered_map用来装载nums数组中的数字和其在数组中对应的下标，数字作为key，下标作为value
        unordered_map<int, int> m;
        //遍历整个数组，每遍历一个数字的时候，就查询unordered_map中是否有数字可以和他相加得到target
        for (int i = 0; i < nums.size(); i++)
        {
            //unordered_map.count是一个查找函数，若查找到该key值，就返回1，没有就返回0
            if (m.count(target - nums[i]))
            {
                //如果满足if条件，那么直接返回两个下标（因为unordered_map中key是数组中的数字，value是下标
                //题目限制了返回值只有一组，所以的话只要查找到一组值满足就可以直接返回
                return {m[target - nums[i]], i};
            }
            //如果上面的if语句没有通过即没有找到那一组值，则将这个数组中的数作为key，对应的下标作为value加到unordered_map中
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
