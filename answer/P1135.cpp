#include <bits/stdc++.h>
using namespace std;
int ans[200 + 10];
int vis[200 + 10]; //��¼�ò��Ƿ񱻷��ʵ�
int f[200 + 10];   //��¼����
int n, a, b, i;
queue<int> q;
int bfs()
{
    q.push(a); //��Ԫ�������
    f[a] = 0;  //��a¥�㿪ʼ��a¥��Ĳ�����ʼ��Ϊ0
    while (!q.empty())
    {
        int x = q.front(); //���׵�¥��
        if (x == b)
            return f[b];
        int tx = x + ans[x]; // �����󵽴��¥��
        int ty = x - ans[x]; //�½��󵽴��¥��
        if (tx >= 1 && tx <= n && vis[tx] == 0)
        {                     //�ж��Ƿ��ڷ�Χ�ں��Ƿ񱻱�ǹ�
            vis[tx] = 1;      //�����ʵ����Ϊ1
            f[tx] = f[x] + 1; //�ò�Ĳ�����ǰ���߹��Ĳ�Ļ����ϼ�һ �������뵱ǰ�Ĳ���������
            q.push(tx);       //���������������¥�����
        }
        if (ty >= 1 && ty <= n && vis[ty] == 0)
        {
            vis[ty] = 1;
            f[ty] = f[x] + 1;
            q.push(ty);
        }
        q.pop(); //��Ԫ�س�����
    }
    return -1;
}
int main()
{
    while (cin >> n >> a >> b)
    {
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis)); //�������룬Ҫ�������
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