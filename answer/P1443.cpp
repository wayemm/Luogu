#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
queue<int> q, q1;                                 //分别表示当前的行和列
vector<vector<int>> a(401, vector<int>(401));     //标记数组，记录马行走过的点
vector<vector<int>> b(401, vector<int>(401, -1)); //答案数组，记录马到达点的最小步数
int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};         //压缩马行走的8个方向
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};

void BFS()
{
    while (!q.empty())
    { //队列中有元素就一直循环
        for (int i = 0; i < 8; i++)
        {                               //依次判断马的8个方向是否可走
            int xx = q.front() + dx[i]; //记录行走后的位置
            int yy = q1.front() + dy[i];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && !a[xx][yy])
            {                                             //判断是否越界，是否被访问过
                a[xx][yy] = 1;                            //标记为访问过
                b[xx][yy] = b[q.front()][q1.front()] + 1; //当前的步数记录为前一个点的步数 +1
                q.push(xx);                               //将当前点入队
                q1.push(yy);
            }
        }
        q.pop(); //当前点的8个方向判断完毕，当前点出队
        q1.pop();
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    q.push(x); //将当前位置作为起点
    q1.push(y);
    a[x][y] = 1; //起点标记为走过
    b[x][y] = 0; //起点的步数为0
    BFS();
    for (int i = 1; i <= n; i++)
    { //输出答案
        for (int j = 1; j <= m; j++)
        {
            printf("%-5d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
