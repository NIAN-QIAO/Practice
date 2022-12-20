#include <string>
#include <iostream>
using namespace std;
// 两种方法
// 1.移动匹配
/*如果目标字符串是S，那么S+S在去除首字母和尾字母的剩余字符串中一定会出现S
例如S=abcdeabcde则S+S=abcdeabcdeabcdeabcde
去除首部和尾部之后则有bcdeabcdeabcdeabcdeabcd
反例S=abcdabc,s+s=abcdabcabcdabc，去除首尾
bcdabcabcdab
感觉像是判断前后是否相等
*/

/*
find函数，返回查询在字符串中的位置如果没有则返回string::npos
*/

// 2.KMP算法
/*如果是由重复子串构成，则最小构成单位就是最长相等前后缀不包含的部分*/
/*
 */
class Solution
{
public:
    bool repeatedSubstringPattern1(string s)
    {
        string s2 = s + s;
        string::iterator it;
        it = s2.begin();
        s2.erase(it);
        it = s2.end() - 1;
        s2.erase(it);
        // cout << s << endl;
        // cout << s2 << endl;
        // cout << s2.find(s);
        if (s2.find(s) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool repeatedSubstringPattern2(string s)
    {
        /*如果是由重复子串构成，则最小构成单位就是最长相等前后缀不包含的部分*/
    }
};
int main()
{
    Solution a;
    string s = "aba";
    bool temp = a.repeatedSubstringPattern1(s);
    cout << temp;
}