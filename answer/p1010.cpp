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
        int temp = 1;         //��aС������2�η�����
        int index = 0;        // temp��ָ��
        while (x >= temp * 2) //Ѱ��temp��index
        {
            temp *= 2;
            index++;
        }

        x -= temp;
        if (index == 0) // 2����η�ֱ�����
            printf("2(%d)", index);
        else if (index == 1) // 2��1�η����2
            cout << 2;
        else //�����ǵĻ�����index���еݹ�
        {
            cout << "2(";
            calculate(index);
            cout << ")";
        }
        if (x > 0) //���һλ������Ӻ�
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