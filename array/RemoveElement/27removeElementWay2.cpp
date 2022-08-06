#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int leftIndex = 0, rightIndex = nums.size() - 1;
    while (leftIndex <= rightIndex)
    {
        while (leftIndex <= rightIndex && nums[leftIndex] != val)
        {
            ++leftIndex;
        } //找相等的元素
        while (leftIndex <= rightIndex && nums[rightIndex] == val)
        {
            --rightIndex;
        } //找不等的元素
        if (leftIndex < rightIndex)
            nums[leftIndex++] = nums[rightIndex--];
    }
    return leftIndex;
}

int main()
{
}
/*相向指针*/