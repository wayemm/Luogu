#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int vis[10];
int a[10];
int cnt, counts = 0;
void dfs(int n, int k, int t)
{
    if (n == cnt)
    {
        for (int i = 1; i < k; i++)
            cout << a[i] << "+";
        cout << a[k] << endl;
    }
    for (int i = 1; i < cnt; i++)
    {
        if ((n + i <= cnt) && i >= t)
        {
            a[k + 1] = i;
            k++;
            dfs(n + i, k, i);
            k--;
        }
    }
}
int main()
{
    cin >> cnt;
    dfs(0, 0, 0);
    return 0;
}
