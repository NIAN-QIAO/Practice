#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;
//先看长度是否相等，一次for循环
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        map<char, int> ttl;
        for (int i = 0; i < s.length(); i++)
        {
            ttl[s[i]]++;
            ttl[t[i]]--;
        }
        for (map<char, int>::iterator it = ttl.begin(); it != ttl.end(); it++)
        {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};