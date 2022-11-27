#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // vector<int> list;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
//什么时候使用哈希法，当我们需要查询一个元素是否出现过
//，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。