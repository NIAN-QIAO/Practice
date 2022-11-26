#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};

/*思路梳理：
前置条件：判断是否为字母异位词可以通过排序后是否相等来判断
思路：map容器、vector容器
遍历所给得字符串数组，对数组内每个元素排列（不改变原先内容）
如果是字母异位词，则可以添加到排序后的map容器对应内容，用排序后的内容作为标识符:line18
之后再获得所有已经拍好序的字符串排序
*/