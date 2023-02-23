#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m, f[N][N], a[N], b[N], sum[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    reverse(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            f[i][j] = -1e9;
            int x = 0, y = 0;
            if (b[j] > a[i])
                x = 1;
            else if (b[j] < a[i])
                x = -1;
            else
                x = 0;
            if (j > 0)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + x);
            if (b[n - (i - j) + 1] > a[i])
                y = 1;
            else if (b[n - (i - j) + 1] < a[i])
                y = -1;
            else
                y = 0;
            f[i][j] = max(f[i][j], f[i - 1][j] + y);
        }
    }
    int maxx = -1e9;
    for (int j = 0; j <= n; j++)
        maxx = max(maxx, f[n][j]);
    cout << maxx * 200;
    return 0;
}