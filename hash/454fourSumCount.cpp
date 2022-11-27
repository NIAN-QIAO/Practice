#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <typeinfo>
using namespace std;
/*stupid 两者之和的plus*/
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> hashTable1;
        unordered_map<int, int> hashTable2;
        for (int m = 0; m < nums1.size(); m++)
        {
            for (int n = 0; n < nums2.size(); n++)
            {
                hashTable1[nums1[m] + nums2[n]]++;
            }
        }
        for (int m = 0; m < nums1.size(); m++)
        {
            for (int n = 0; n < nums2.size(); n++)
            {
                hashTable2[nums3[m] + nums4[n]]++;
            }
        }
        int res = 0;
        for (auto iter = hashTable1.begin(); iter != hashTable1.end(); iter++)
        {
            cout << typeid(iter).name() << endl;
            if (hashTable2.count(0 - iter->first))
            {
                res += hashTable2[0 - iter->first] * iter->second;
            }
        }
        // for (auto it : hashTable1)
        // {
        //     // cout << typeid(it).name() << endl;
        //     if (hashTable2.count(0 - it.first))
        //     {
        //         res += hashTable2[0 - it.first] * it.second;
        //     }
        // }
        return res;
    }
};