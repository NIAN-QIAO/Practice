#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0)); // n*n的矩阵
    int startx = 0, starty = 0;
    int loop = n / 2;   //螺旋次数
    int center = n / 2; //奇数存在中心
    int count = 1;      //给矩阵中的数填入
    int edge = 1;       //边缘长度需要缩减
    int i, j;
    while (loop--)
    {
        //模拟每个螺旋顺时针填入矩阵
        for (j = starty; j < n - edge; j++)
        {
            res[startx][j] = count++;
        } //从左到右
        for (i = startx; i < n - edge; i++)
        {
            res[i][j] = count++;
        } //从上到下
        for (; j > starty; j--)
        {
            res[i][j] = count++;
        } //从右到左
        for (; i > startx; i--)
        {
            res[i][j] = count++;
        } //从下到上
        startx++;
        starty++;
        edge++;
    }
    if (n % 2)
    {
        res[center][center] = count;
    }
    return res;
}
int main()
{
}