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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m;
        vector<int> res;
        for (auto i : nums1)
            ++m[i];
        for (auto i : nums2)
            if (m.count(i) && m[i])
                --m[i], res.push_back(i);
        return res;
    }
};