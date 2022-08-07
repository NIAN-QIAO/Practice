#include <iostream>
#include <vector>
using namespace std;
/*相向指针**/
vector<int> sortedSquares(vector<int> &nums)
{
    int leftIndex = 0, rightIndex = nums.size() - 1;
    vector<int> result(nums.size(), 0);
    int i = nums.size() - 1;
    while (leftIndex <= rightIndex)
    {
        if (nums[leftIndex] * nums[leftIndex] <= nums[rightIndex] * nums[rightIndex])
        {
            result[i--] = nums[rightIndex] * nums[rightIndex];
            rightIndex--;
        }
        else
        {
            result[i--] = nums[leftIndex] * nums[leftIndex];
            leftIndex++;
        }
    }
    return result;
}
int main()
{
}