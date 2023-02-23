#include<iostream>
using namespace std;
long int tree[1000005];
int main()
{
    long int n, m, st = 0, ed = 1e9, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }
    while (st <= ed)
    {
        long int height = 0, mid = (st + ed) / 2;
        ;
        for (int i = 1; i <= n; i++)
        {
            height += tree[i] - min(tree[i], mid);
        }
        if (height >= m)
            st = mid + 1, ans = mid;
        else
            ed = mid - 1;
    }
    cout << ans;
    return 0;
}
