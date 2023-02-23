#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
int fun(int a, int b, int c)
{
    int d = 0;
    if (a > b && a > c)
        d = a;
    if (b > a && b > c)
        d = b;
    else
        d = c;
    return d;
}
int main()
{

    int n, k, l, ii, jj, min = 5;
    cin >> n >> k;
    int *v = new int[n];
    int *w = new int[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        v[i] = l;
        if (l / 10 == 0)
        {
            w[i] = 1;
            if (w[i] < min)
                min = w[i];
            continue;
        }
        if (l / 100 == 0)
        {
            w[i] = 2;
            if (w[i] < min)
                min = w[i];
            continue;
        }
        if (l / 1000 == 0)
        {
            w[i] = 3;
            if (w[i] < min)
                min = w[i];
            continue;
        }
        if (l / 10000 == 0)
        {
            w[i] = 4;
            if (w[i] < min)
                min = w[i];
            continue;
        }
    }
    long long m[200][200];
    memset(m, 0, sizeof(m));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= w[i])
            {
                m[i][j] = fun(m[i - 1][j], 
                (m[i - 1][j - w[i]] + v[i] * pow(10, (j - w[i]) / min * min)),
                 (m[i - 1][j - w[i]] * pow(10, w[i]) + v[i]));
                ii = i;
                jj = j;
            }
            else
            {
                m[i][j] = m[i - 1][j];
            }
        }
    }

    cout << m[ii][jj];
    cout << endl;
    system("pause");
    return 0;
}