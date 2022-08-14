#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*最小覆盖子串*/
/*给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：
输入：s = "a", t = "a"
输出："a"
示例 3:
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
提示：
1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
string minWindow(string s, string t)
{
    unordered_map<char, int> s1, t1; //与 map的比较
    for (auto a : t)
        t1[a]++; //统计字符串t中的元素内容以及对应的个数
    string res;
    int count = 0;                            //可认为是对j-i区间内，s串满足t串的元素个数
    for (int i = 0, j = 0; i < s.size(); i++) // j在前，i在后
    {
        s1[s[i]]++;
        if (s1[s[i]] <= t1[s[i]])
        {
            count++;
        }
        while (s1[s[j]] > t1[s[j]])
        {
            s1[s[j++]]--; //收缩滑动窗口
        }
        if (count == t.size())
        {
            if (res.empty() || i - j + 1 < res.size())
                res = s.substr(j, i - j + 1);
        }
    }
    return res;
}
int main()
{
}