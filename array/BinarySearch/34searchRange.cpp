#include <iostream>
#include <vector>
using namespace std;
/*给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int binarySearch(vector<int> &nums, int target)
{
    int leftborder = -1, rightborder = -1;
    int left = 0, right = nums.size() - 1;
    int mid = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else //相等
        {
            return mid;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int left = -1, right = -1;
    int var = binarySearch(nums, target);
    if (var == -1)
        return {-1, -1};
    else
    {
        left = var;
        right = var;
        while (nums[left] == target)
        {
            left--;
            if (left < 0)
            {
                break;
            }
        }
        while (nums[right] == target)
        {
            right++;
            if (right > nums.size() - 1)
            {
                break;
            }
        }
        return {left + 1, right - 1};
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    int target = 1;
    searchRange(nums, target);
}
/*总感觉没有吃透，右边界和左边界独立逼近没有想明白*/