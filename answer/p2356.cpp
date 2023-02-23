#include <stdio.h>
#include <stdlib.h>

void method(int n01, int array[11110][11110])
{
    int i, j;
    int sum, max, judge;
    sum = max = judge = 0;
    for (i = 1; i <= n01; i++)
    {
        for (j = 1; j <= n01; j++)
        {
            if (array[i][j] == 0)
            {
                judge = 1;
                for (int a = 1; a <= n01; a++)
                {
                    sum += array[i][a];
                }
                for (int b = 1; b <= n01; b++)
                {
                    sum += array[b][j];
                }
            }
            if (sum > max)
            {
                max = sum;
            }
            sum = 0;
        }
    }
    if (judge == 0)
    {
        printf("Bad Game!");
    }
    else
    {
        printf("%d", max);
    }
}
int main()
{
    int array[11110][11110];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    method(n, array);
}