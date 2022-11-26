#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;
/*给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
            return false;
        unordered_map<char, int> ttl;
        for (int i = 0; i < ransomNote.length(); i++)
        {
            ttl[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.length(); i++)
        {
            ttl[magazine[i]]--;
        }
        for (unordered_map<char, int>::iterator it = ttl.begin(); it != ttl.end(); it++)
        {
            if (it->second > 0)
                return false;
        }
        return true;
    }
};