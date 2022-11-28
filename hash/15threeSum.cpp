#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <typeinfo>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> list;
        int length = nums.size();
        if (length < 3)
            return list;
        sort(nums.begin(), nums.end());
        int k, i, j;
        for (k = 0; k <= length - 3; k++)
        {
            if (nums[k] > 0)
                return list;
            if (k > 0 && nums[k] == nums[k - 1]) //去除开始的重复，减少不必要的循环
                continue;
            for (i = k + 1, j = length - 1; i < j;)
            {
                if (nums[k] + nums[i] + nums[j] > 0)
                    j--;
                else if (nums[k] + nums[i] + nums[j] < 0)
                    i++;
                else
                {
                    list.push_back(vector<int>{nums[j], nums[i], nums[k]});
                    while (i < j && nums[j] == nums[j - 1])
                        j--;
                    while (i < j && nums[i] == nums[i + 1])
                        i++;
                    i++;
                    j--;
                }
            }
        }
        return list;
    }
};