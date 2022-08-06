#include <iostream>
using namespace std;
int mySqrt(int x)
{
    if (x <= 1)
        return x;
    int left = 0, right = x;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if ((long)mid * mid <= x)
        {
            left = mid + 1;
        }
        else if ((long)mid * mid == x)
        {
            return mid - 1;
        }
        else
            right = mid - 1;
    }
    return (long)left * left <= x ? left : left - 1;
}
int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x);
}
