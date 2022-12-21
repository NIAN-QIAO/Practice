#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    class MyQueue
    {
    public:
        deque<int> que;
        // 使用deque实现单调队列
        // 每次弹出，比较当前弹出数值是否等于队列出口元素数值，如果相等则弹出
        // 同时pop之间应该检查队列当前是否为空
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于入口
        // 数值
        // 这样就保持了队列里的数值是单调从大到小的了
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) // 将前k的元素放进队列
        {
            que.push(nums[i]);
        }
        result.push_back(que.front()); // 记录前k的元素最大值
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
int main()
{
}