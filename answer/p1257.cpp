#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int Max = 10005;
struct node
{
    int x, y;
} a[Max];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    double Min = 0x7fffffff;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            Min = min(Min, sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y)));
    printf("%.4lf\n", Min);
    return 0;
}