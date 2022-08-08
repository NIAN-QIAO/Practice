#include <iostream>
#include <vector>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int beginIndex = 0, endIndex = 0;
    int subLength = -1; //窗口的长度
    int left = -1, right = -2;
    int count = 0;
    int result = 2; //最小长度也为2
    if (fruits.size() <= 2)
        return fruits.size();
    for (endIndex = 0; endIndex < fruits.size(); endIndex++)
    {
        count++;
        if (count == 1)
            left = fruits[endIndex];
        else if (count == 2)
        {
            while (left == fruits[endIndex])
            {
                count++;
                endIndex++;
                if (endIndex >= fruits.size())
                    return fruits.size();
            }
            right = fruits[endIndex];
        }
        else
        {
            if (fruits[endIndex] == left || fruits[endIndex] == right)
            {
                subLength = endIndex - beginIndex + 1; //长度
                result = subLength > result ? subLength : result;
            }
            else
            {
                subLength = endIndex - beginIndex; //长度
                result = subLength > result ? subLength : result;
                left = fruits[endIndex - 1];
                right = fruits[endIndex];
                beginIndex = endIndex - 1;
                while ((beginIndex > 0) && fruits[beginIndex - 1] == left)
                {
                    beginIndex--;
                }
            }
        }
    }
    return result;
}
int main()
{ //[3,3,3,1,2,1,1,2,3,3,4]
    vector<int> fruits;
    fruits.push_back(3);
    fruits.push_back(3);
    fruits.push_back(3);

    fruits.push_back(1);
    fruits.push_back(2);
    fruits.push_back(1);
    fruits.push_back(1);

    fruits.push_back(2);
    fruits.push_back(3);
    fruits.push_back(3);
    fruits.push_back(4);

    cout << totalFruit(fruits);
}