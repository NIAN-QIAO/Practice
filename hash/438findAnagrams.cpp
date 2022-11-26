#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // if (s.length() < p.length())
        //     return {};
        // vector<int> list;
        // string temp;
        // sort(p.begin(), p.end());
        // for (int i = 0; i <= s.length() - p.length(); i++)
        // {
        //     temp = s.substr(i, p.length());
        //     sort(temp.begin(), temp.end());
        //     if (p == temp)
        //         list.push_back(i);
        // }
        // return list;/*一次for循环 由0~s.lenth-p.length,关键在于获取数组某一段的内容 */
        // 主播感觉思路是没问题的，但是超时了，保留

        //滑动窗口解法
        if (s.size() < p.size())
            return {};
        vector<int> hashTable(26);
        for (auto ch : p)
        {
            ++hashTable[ch - 'a'];
        } //统计p序列的元素
        vector<int> ret;
        for (int l = 0, r = 0; r < s.size(); ++r)
        {
            hashTable[s[r] - 'a']--;
            while (hashTable[s[r] - 'a'] < 0)
            {
                hashTable[s[l] - 'a']++;
                ++l;
            }
            if (r - l + 1 == p.size())
                ret.push_back(l);
        }
        return ret;
    }
};
// slidingWindow不是死板的定死长度，而是不满足条件时，左移长度，当满足条件时填入队列。。