#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int sum = 0;
        unordered_set<int> set;
        while (true)
        {
            sum = getSum(n);
            if (sum == 1)
                return true;
            if (set.find(sum) != set.end())
                return false;
            else
                set.insert(sum);
            n = sum;
        }
    }
};