#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n;
int k;
long long int a[5000005];

void quicksort(int left, int right);
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    nth_element(a, a + k, a + n);
    cout << a[k];
    return 0;
}