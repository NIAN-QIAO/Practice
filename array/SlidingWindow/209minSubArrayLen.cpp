/*就目前来看，滑动窗口和双指针法很类似，都是将两个for循环的内容变成一个for循环可以解决的问题*/
#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int beginIndex = 0, endIndex = 0; //窗口的起始值
    int sum = 0, subLength = 0;       // sum为窗口内部的数值和
    int result = INT32_MAX;
    for (endIndex = 0; endIndex < nums.size(); endIndex++)
    {
        sum += nums[endIndex];
        while (sum >= target)
        {
            subLength = endIndex - beginIndex + 1;
            result = result < subLength ? result : subLength;
            sum -= nums[beginIndex++]; //变更起始位置
        }
    }
    return result == INT32_MAX ? 0 : result; //没有则返回零
}
int main()
{
    /*感觉和双指针写法不同，更关注窗口内部的东西，示例代码更为简洁高效*/
}