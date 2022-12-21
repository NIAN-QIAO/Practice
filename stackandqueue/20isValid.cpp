#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> left;
        stack<char> right;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left.push(s[i]);
                right.push(')');
            }
            else if (s[i] == '[')
            {
                left.push(s[i]);
                right.push(']');
            }
            else if (s[i] == '{')
            {
                left.push(s[i]);
                right.push('}');
            }
            else if (!right.empty())
            {
                if (s[i] == right.top())
                {
                    right.pop();
                    left.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (left.empty() && right.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string s = "]";
    Solution a;
    cout << a.isValid(s);
}