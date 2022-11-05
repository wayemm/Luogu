/*
p1008三连击
*/
#include <iostream>
using namespace std;
bool Deng(int, int, int); //函数原型声明  筛选出符合条件的三个数并返回。
int main()
{
    int A = 1, B = 2, C = 3;
    for (size_t i = 100 / A; C * i < 1000; i++)
    {
        if (Deng(A * i, B * i, C * i) == true)
        {
        }
        else
        {
            cout << A * i << ' ' << B * i << ' '
                 << C * i << endl;
        }
    }
    return 0;
}
bool Deng(int M, int N, int Q)
{

    //分别将9个数字放在数组中
    int array[9] = {0};
    array[0] = M / 100;
    array[1] = M % 100 / 10;
    array[2] = M % 10;
    array[3] = N / 100;
    array[4] = N % 100 / 10;
    array[5] = N % 10;
    array[6] = Q / 100;
    array[7] = Q % 100 / 10;
    array[8] = Q % 10;
    for (size_t i = 0; i != 9; i++) //判断是否有重复数，也可以使用标记数组即当数字出现过一次后既为一
    {
        for (size_t j = i + 1; j != 9; j++)
        {
            if (array[i] == array[j] || array[i] == 0 || array[j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}