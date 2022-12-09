#include <string>
#include <iostream>

// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

// 链接：https://leetcode.cn/problems/reverse-string-ii
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int left = 0, right = 2 * k - 1, mid = k - 1; // 框定
        int begin = left, end = mid;                  // 左右指针
        int length = 2 * k;
        char temp;
        // cout << right << endl;
        while (right <= s.size() - 1)
        {
            cout << begin << "  " << end << endl;
            while (begin < end)
            {
                temp = s[begin];
                s[begin] = s[end];
                s[end] = temp; // 交换完毕
                begin++;
                end--;
            }
            // cout << left << "  " << right << endl;
            left = left + length;
            right = right + length;
            mid = mid + 2 * k; // 新范围(范围错误！！！)
            begin = left;
            end = mid;
        }
        if (right > s.size() - 1)
        {
            end = s.size() - 1;
            // cout << end << endl;
            /// cout << begin << end;
            if (end - begin + 1 < k) // 符号数量小于k
            {
                while (begin < end)
                {
                    temp = s[begin];
                    s[begin] = s[end];
                    s[end] = temp; // 交换完毕
                    begin++;
                    end--;
                }
            }
            else if (end - begin + 1 >= k) // 剩余字符数量大于K个
            {
                end = begin + k - 1;
                while (begin < end)
                {
                    temp = s[begin];
                    s[begin] = s[end];
                    s[end] = temp; // 交换完毕
                    begin++;
                    end--;
                }
            }
        }
        // cout << left << end << endl;

        //"jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfx  ubewllxzqhpasguvlrxt kgatzfybprfmmfithphc cxfsogsgqsnvckjvnskk"
        //"jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfx  txrlvugsaphqzxllwebu kgatzfybprfmmfithphc cxfsogsgqsnvckjvnskk"
        // cout << s;
        return s;
    }
};
int main()
{
    string s = "krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc";
    int k = 20;
    Solution a;
    a.reverseStr(s, k);
}