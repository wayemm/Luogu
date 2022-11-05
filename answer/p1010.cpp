#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 100001
#define MOD 123
#define E 1e-6
using namespace std;
void calculate(int x)
{
    while (x > 0)
    {
        int temp = 1;         //比a小的最大的2次方的数
        int index = 0;        // temp的指数
        while (x >= temp * 2) //寻找temp与index
        {
            temp *= 2;
            index++;
        }

        x -= temp;
        if (index == 0) // 2的零次方直接输出
            printf("2(%d)", index);
        else if (index == 1) // 2的1次方输出2
            cout << 2;
        else //都不是的话，对index进行递归
        {
            cout << "2(";
            calculate(index);
            cout << ")";
        }
        if (x > 0) //最后一位不输出加号
            cout << "+";
    }
}
int main()
{
    int n;

    cin >> n;
    calculate(n);

    return 0;
}