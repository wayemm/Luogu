#include <stdio.h>
int a[100000 + 100];
void quicksort(int left, int right)
{
    int i = left, j = right, t;
    int mid = a[(left + right) / 2]; // 请注意，在处理的过程中a[(left+right)/2]的值是会变化的
    while (i <= j)
    { // i,j的值是会跳跃的,循环结束时i>j
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i < right)
        quicksort(i, right);
    if (left < j)
        quicksort(left, j);
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(0, n - 1);
    printf("%d", a[0]);
    for (i = 1; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}