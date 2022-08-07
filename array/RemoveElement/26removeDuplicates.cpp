#include <iostream>
#include <vector>
using namespace std;
/*移除数组中的重复元素，返回数组的长度*/
/*快慢指针，记得缩减后的数组用的是慢指针*/
int removeDuplicates(vector<int> &nums)
{
    int slowIndex = 0, fastIndex = 0;
    for (fastIndex = 1; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != nums[slowIndex])
        {
            nums[slowIndex + 1] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex + 1;
}
int main()
{
}