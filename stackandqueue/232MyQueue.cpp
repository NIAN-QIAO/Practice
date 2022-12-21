#include <stack>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }
    int pop()
    {
        if (stOut.empty()) // 判断是否为空
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        return result;
    }

    int peek()
    {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res);       // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */