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
bool isPerfectSquare(int num)
{
    int res = mySqrt(num);
    if (res * res == num)
        return true;
    else
        return false;
}
int main()
{
    int num;
    cin >> num;
    cout << isPerfectSquare(num);
}
/*1+3+5+7+9+…+(2n-1)=n^2，即完全平方数肯定是前n个连续奇数的和*/