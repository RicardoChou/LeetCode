/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack
{
    //用一个辅助栈，当主栈压入一个元素时，辅助栈同时压入主栈中最小的元素
public:
    //主栈
    stack<int> x_stack;
    //辅助栈
    stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack()
    {
        //初始化时辅助栈压入初始值
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        //主栈压入元素时，辅助栈同时压入最小元素
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop()
    {
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        //返回主栈中栈顶的元素
        return x_stack.top();
    }

    int getMin()
    {
        //辅助栈栈顶保存的是当前主栈中最小的元素
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
