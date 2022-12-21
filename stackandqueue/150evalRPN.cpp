#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// atoi(需要的是char*所以先用c_str()转换)
// stoi则可以直接使用
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;
        string num1, num2;
        long long num3 = 0;
        for (auto &it : tokens)
        {
            if (it == "/")
            {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                num3 = stoll(num2) / stoll(num1);
                st.push(to_string(num3));
            }
            else if (it == "*")
            {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                num3 = stoll(num1) * stoll(num2);
                st.push(to_string(num3));
            }
            else if (it == "+")
            {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                num3 = stoll(num1) + stoll(num2);
                st.push(to_string(num3));
            }
            else if (it == "-")
            {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                num3 = stoll(num2) - stoll(num1);
                st.push(to_string(num3));
            }
            else
            {
                st.push(it);
            }
        }
        return stoi(st.top());
    }
};
int main()
{
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    Solution a;
    cout << a.evalRPN(tokens);
    // = [ "4", "13", "5", "/", "+" ];
}