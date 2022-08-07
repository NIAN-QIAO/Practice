/*快慢指针*/
/*删除数组中的的指定值，返回数组长度*/
#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int fastIndex = 0, slowIndex = 0;
    for (fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != val)
        {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}
int main()
{
}