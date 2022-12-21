#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        if (!s.size())
            return s;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
                st.push(s[i]);
            else if (st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    string s = "abbaca";
    Solution a;
    a.removeDuplicates(s);
}