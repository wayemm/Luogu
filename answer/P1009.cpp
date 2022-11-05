#include <stdio.h>
int main()
{
    int n, i, j, m = 0, tmp, up;
    int a[10005] = { 0 }, b[10005] = { 1 };
    scanf("%d", &n);
    if (n == 0) printf("1");
    else {
        for (; n > 0; n--)
        {
            for (i = 0; i <= 10000; i++)
                b[i] = 0;
            b[0] = 1;
            for (i = 2; i <= n; i++)
            {
                for (j = 0, up = 0, tmp = 0; j <= 10000; j++)
                {
                    tmp = b[j] * i + up;
                    b[j] = tmp % 10;
                    up = tmp / 10;
                }
            }
            for (j = 0, up = 0, tmp = 0; j <= 10000; j++)
            {
                tmp = a[j] + b[j] + up;
                a[j] = tmp % 10;
                up = tmp / 10;
            }
        }
        for (i = 10000; i >= 0; i--)
        {
            if (a[i] == 0 && m == 0);
            else {
                m = 1;
                printf("%d", a[i]);
            }
        }
    }
}
