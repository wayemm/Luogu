#include <iostream>
#include <cstdio>
using namespace std;

int n;
int total;
int is[5][100];

void print()
{
    if (total < 3)
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", is[1][i]);
        printf("\n");
    }
    total++;
}

void dfs(int m)
{
    if (m > n)
    {
        print();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!is[2][i] && !is[3][m + i] && !is[4][m - i + n])
        {
            is[1][m] = i;
            is[2][i] = 1;
            is[3][m + i] = 1; 
            is[4][m - i + n] = 1;
            dfs(m + 1);
            is[2][i] = 0;
            is[3][m + i] = 0; 
            is[4][m - i + n] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    printf("%d", total);
    return 0;
}
