#include <iostream>
#include <string>
using namespace std;
//**不要使用辅助空间，空间复杂度要求为O(1)**

// split函数、erase函数
// resize函数

// 所以解题思路如下：
// 移除多余空格
// 将整个字符串反转
// 将每个单词反转
class Solution
{
public:
    string reverseWords(string s)
    { // 1.去除多余空格
        int slowIndex = 0, fastIndex = 1;
        // 1.1去除前面的空格
        if (s[slowIndex] == ' ')
        {
            while (s[fastIndex] == ' ')
            {
                fastIndex++;
            }
            s[slowIndex++] = s[fastIndex++]; // 确保第一个不是空格
        }
        else
        {
            slowIndex++; // 开始替换的元素为全新的元素
        }
        // cout << s << endl;
        //  cout << slowIndex << "  " << fastIndex << endl;
        //    1.2 去除中间冗余的空格
        while (fastIndex <= s.size() - 1)
        {
            if (s[fastIndex] == ' ')
            {
                if (s[slowIndex - 1] == ' ')
                {
                    fastIndex++;
                }
                else
                {
                    s[slowIndex++] = s[fastIndex++];
                }
            }
            else
            {
                s[slowIndex++] = s[fastIndex++];
            }
        }
        s.resize(slowIndex);
        // 1.3去除尾部空格
        if (s[s.size() - 1] == ' ')
        {
            s.resize(slowIndex - 1);
        }
        // 2.将字符串翻转。
        slowIndex = 0;
        fastIndex = s.size() - 1;
        char temp;
        while (slowIndex < fastIndex)
        {
            temp = s[slowIndex];
            s[slowIndex] = s[fastIndex];
            s[fastIndex] = temp;
            slowIndex++;
            fastIndex--;
        }
        cout << s << endl;
        // 3.将内部每个字符串翻转
        slowIndex = 0;
        fastIndex = 0;
        int slow, fast;
        char changeWord;
        // 找出应该替换的部分
        while (fastIndex < s.size() && s[fastIndex] != ' ')
        {
            fastIndex++;
        }
        fastIndex--; // 第一块应该替换的部分
        while (fastIndex < s.size())
        {
            slow = slowIndex;
            fast = fastIndex;
            while (slow < fast) // 字符串翻转
            {
                changeWord = s[slow];
                s[slow] = s[fast];
                s[fast] = changeWord;
                slow++;
                fast--;
            }
            // cout << s << endl;
            slowIndex = fastIndex + 2; // 最后一字符跳过空格
            fastIndex = slowIndex;
            while (fastIndex < s.size() && s[fastIndex] != ' ')
            {
                fastIndex++;
            }
            fastIndex--;
            // cout << slowIndex << " " << fastIndex << endl;
        }
        cout << s << endl;
        // return s;
    }
};
int main()
{
    string s = "EPY2giL";
    Solution a;
    a.reverseWords(s);
}