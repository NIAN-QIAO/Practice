#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
/*从后向前双指针*/
bool backspaceCompare(string s, string t)
{
    int sSkipNum = 0, tSkipNum = 0;
    int i = s.size() - 1;
    int j = t.size() - 1;
    while (1)
    {
        while (i >= 0)
        {
            if (s[i] == '#')
                sSkipNum++;
            else
            {
                if (sSkipNum > 0)
                    sSkipNum--;
                else
                    break;
            }
            i--;
        }
        while (j >= 0)
        {
            if (t[j] == '#')
                tSkipNum++;
            else
            {
                if (tSkipNum > 0)
                    tSkipNum--;
                else
                    break;
            }
            j--;
        }
        if (i < 0 || j < 0)
            break;
        if (s[i] != t[j])
            return false;
        i--;
        j--;
    }
    if (i == -1 && j == -1)
        return true;
    return false;
}
int main()
{
    string s = "ab##";
    string t = "c#d#";
    cout << backspaceCompare(s, t);
}