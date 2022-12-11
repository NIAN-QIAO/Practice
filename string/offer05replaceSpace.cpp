#include <string>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s) // 思路遇到空格字符，替换成%再将
    {                             // 后续后移两个字符，补充'2'，'0'
        int i = 0;
        int a = 0;
        int length = 0;
        while (i < s.size())
        {
            if (s[i] == ' ') // 如果遇到空白字符
            {
                s[i] = '%';
                s = s + "00";
                for (length = s.size() - 3; length != i; length--)
                {
                    s[length + 2] = s[length];
                }
                s[i + 1] = '2';
                s[i + 2] = '0';
            }
            i++;
        }
        cout << s;
        return s;
    }
};
int main()
{
    Solution a;
    string s = "We are happy";
    a.replaceSpace(s);
    // cout << a.replaceSpace(s);
}