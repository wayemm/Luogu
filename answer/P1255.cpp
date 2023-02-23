#include <iostream>
#include <cstdio>
using namespace std;
int f[5050][5050], len = 1; 
void hpa(int m)             //高精度加法，m表示阶数
{
    for (int i = 1; i <= len; i++)
        f[m][i] = f[m - 1][i] + f[m - 2][i]; //套用斐波那契数列递推公式
    for (int i = 1; i <= len; i++)           //遍历每一个数位
    {
        if (f[m][i] >= 10) 
        {
            f[m][i + 1] += f[m][i] / 10;
            f[m][i] %= 10;
            if (f[m][len + 1]) 
                len++;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    f[1][1] = 1; //一阶有一种
    f[2][1] = 2; //二阶有两种
    for (int i = 3; i <= n; i++)
        hpa(i);                    //调用高精度加法的函数
    for (int i = len; i >= 1; i--) //倒序输出
        printf("%d", f[n][i]);
    return 0;
}