#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return {};
    int rows = matrix.size(), columns = matrix[0].size();
    int total = rows * columns;
    vector<int> res(total);     // 使用vector定义一个一维数组存放结果
    int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
    int loop = min(rows, columns) / 2;
    // 本题的loop计算与59.螺旋矩阵II算法略微差异，因为存在rows和columns两个维度，可自行分析，loop只能取min(rows, columns)，例如rows = 5, columns = 7，那loop = 5 / 7 = 2
    int mid = min(rows, columns) / 2;
    // 1、同样的原理，本题的mid计算也存在上述差异；
    // 2、
    //如果min(rows, columns)为偶数，则不需要在最后单独考虑矩阵最中间位置的赋值
    //如果min(rows, columns)为奇数，则矩阵最中间位置不只是[mid][mid],而是会留下来一个特殊的中间行或者中间列，具体是中间行还是中间列，要看rows和columns的大小，如果rows > columns,则是中间列，相反，则是中间行
    //相信这一点不好理解，建议自行画图理解
    int count = 0;  // 用来给矩阵中每一个空格赋值
    int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
    int i, j;
    while (loop--)
    {
        i = startx;
        j = starty;

        // 下面开始的四个for就是模拟转了一圈
        // 模拟填充上行从左到右(左闭右开)
        for (j = starty; j < starty + columns - offset; j++)
        {
            res[count++] = matrix[startx][j];
        }
        // 模拟填充右列从上到下(左闭右开)
        for (i = startx; i < startx + rows - offset; i++)
        {
            res[count++] = matrix[i][j];
        }
        // 模拟填充下行从右到左(左闭右开)
        for (; j > starty; j--)
        {
            res[count++] = matrix[i][j];
        }
        // 模拟填充左列从下到上(左闭右开)
        for (; i > startx; i--)
        {
            res[count++] = matrix[i][starty];
        }

        // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
        startx++;
        starty++;

        // offset 控制每一圈里每一条边遍历的长度
        offset += 2;
    }

    // 如果min(rows, columns)为奇数的话，需要单独给矩阵最中间的位置赋值
    if (min(rows, columns) % 2)
    {
        if (rows > columns)
        {
            for (int i = mid; i < mid + rows - columns + 1; ++i)
            {
                res[count++] = matrix[i][mid];
            }
        }
        else
        {
            for (int i = mid; i < mid + columns - rows + 1; ++i)
            {
                res[count++] = matrix[mid][i];
            }
        }
    }
    return res;
}
int main()
{
}