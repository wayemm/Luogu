#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
queue<int> q, q1;                                 //�ֱ��ʾ��ǰ���к���
vector<vector<int>> a(401, vector<int>(401));     //������飬��¼�����߹��ĵ�
vector<vector<int>> b(401, vector<int>(401, -1)); //�����飬��¼��������С����
int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};         //ѹ�������ߵ�8������
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};

void BFS()
{
    while (!q.empty())
    { //��������Ԫ�ؾ�һֱѭ��
        for (int i = 0; i < 8; i++)
        {                               //�����ж����8�������Ƿ����
            int xx = q.front() + dx[i]; //��¼���ߺ��λ��
            int yy = q1.front() + dy[i];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && !a[xx][yy])
            {                                             //�ж��Ƿ�Խ�磬�Ƿ񱻷��ʹ�
                a[xx][yy] = 1;                            //���Ϊ���ʹ�
                b[xx][yy] = b[q.front()][q1.front()] + 1; //��ǰ�Ĳ�����¼Ϊǰһ����Ĳ��� +1
                q.push(xx);                               //����ǰ�����
                q1.push(yy);
            }
        }
        q.pop(); //��ǰ���8�������ж���ϣ���ǰ�����
        q1.pop();
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    q.push(x); //����ǰλ����Ϊ���
    q1.push(y);
    a[x][y] = 1; //�����Ϊ�߹�
    b[x][y] = 0; //���Ĳ���Ϊ0
    BFS();
    for (int i = 1; i <= n; i++)
    { //�����
        for (int j = 1; j <= m; j++)
        {
            printf("%-5d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
