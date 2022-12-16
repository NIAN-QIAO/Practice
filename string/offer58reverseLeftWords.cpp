#include <string>
#include <iostream>
#include <string>
using namespace std;
// 全局翻转
// 局部翻转
// 双指针
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        int leftIndex = 0;
        int midIndex = n - 1, rightIndex = s.size() - 1;
        char temp;
        while (leftIndex < midIndex)
        {
            temp = s[leftIndex];
            s[leftIndex] = s[midIndex];
            s[midIndex] = temp;
            leftIndex++;
            midIndex--;
        }
        midIndex = n;
        while (midIndex < rightIndex)
        {
            temp = s[midIndex];
            s[midIndex] = s[rightIndex];
            s[rightIndex] = temp;
            midIndex++;
            rightIndex--;
        }
        // cout << s << endl;
        leftIndex = 0;
        rightIndex = s.size() - 1;
        while (leftIndex < rightIndex)
        {
            temp = s[leftIndex];
            s[leftIndex] = s[rightIndex];
            s[rightIndex] = temp;
            leftIndex++;
            rightIndex--;
        }
        // cout << s << endl;
        return s;
    }
};
int main()
{
    string s = "abcdefg";
    int n = 2;
    Solution a;
    a.reverseLeftWords(s, n);
}