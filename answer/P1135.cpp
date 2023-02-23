#include <bits/stdc++.h>
using namespace std;
int ans[200 + 10];
int vis[200 + 10]; //记录该层是否被访问到
int f[200 + 10];   //记录步数
int n, a, b, i;
queue<int> q;
int bfs()
{
    q.push(a); //首元素入队列
    f[a] = 0;  //从a楼层开始，a楼层的步数初始化为0
    while (!q.empty())
    {
        int x = q.front(); //队首的楼层
        if (x == b)
            return f[b];
        int tx = x + ans[x]; // 上升后到达的楼层
        int ty = x - ans[x]; //下降后到达的楼层
        if (tx >= 1 && tx <= n && vis[tx] == 0)
        {                     //判断是否在范围内和是否被标记过
            vis[tx] = 1;      //被访问到标记为1
            f[tx] = f[x] + 1; //该层的步数在前面走过的层的基础上加一 ，即存入当前的操作步骤书
            q.push(tx);       //上升后符合条件的楼层入队
        }
        if (ty >= 1 && ty <= n && vis[ty] == 0)
        {
            vis[ty] = 1;
            f[ty] = f[x] + 1;
            q.push(ty);
        }
        q.pop(); //首元素出队列
    }
    return -1;
}
int main()
{
    while (cin >> n >> a >> b)
    {
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis)); //多组输入，要清空数组
        while (!q.empty())
            q.pop();
        if (n == 0)
            return 0;
        for (i = 1; i <= n; i++)
            cin >> ans[i];
        int cnt = bfs();
        printf("%d\n", cnt);
    }
}