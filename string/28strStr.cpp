#include <string>
#include <iostream>
#include <string>
using namespace std;
// KMP:
// 出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。
// next:prefix table前缀表
// 模式串与前缀表对应位置的数字表示的就是：下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀。
// 字符串的前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串

// 思路：搭建前缀表、通过前缀表匹配、查找是否存在对应字符串
// 1.初始化next数组；2.前后缀不相同的情况；3.前后缀相同的情况；4.更新next数组
class Solution
{
public:
    void getstr(int *next, const string &s)
    {
        int i; // i是后缀末尾，j是前缀末尾，还代表着i包括i之前的子串的最长相等前后缀的长度
        // 1.初始化
        int j = 0;
        next[0] = 0;

        for (i = 1; i < s.size(); i++)
        {
            // 2.不相等
            while (j > 0 && s[i] != s[j]) // j-1越界
            {
                j = next[j - 1];
            }
            // 3.相等
            if (s[i] == s[j])
            {
                j++;
            }
            // 4.更新
            next[i] = j;
            cout << "next[" << i << "]:" << j << endl;
        }
    }
    int strStr(string haystack, string needle)
    {
        // 1.构建前缀表
        if (needle.size() == 0)
            return 0;
        // int next[needle.size()];
        int *next = new int[needle.size()];
        getstr(next, needle);
        // 比对
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        delete[] next;
        return -1;
    }
};
int main()
{
    Solution a;
    string s = "abaabcaba";
}