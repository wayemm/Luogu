#include <iostream>
#include <cstring>

using namespace std;

typedef int State[9]; //���塰State������
const int maxstate = 1000000;
State st[maxstate], goal = {1, 2, 3, 8, 0, 4, 7, 6, 5}; //��������
int dist[maxstate];
//��ӡ�����ױ������int fa[maxstate];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void init_lookup_table();
int try_to_insert(int s);

// bfs,����Ŀ��״̬�µ�st�����±�
int bfs()
{
    //��ʼ�����ұ�
    init_lookup_table();
    //�����±�0
    int front = 1, rear = 2;

    while (front < rear)
    {
        //����
        State &s = st[front];
        //����ҵ�Ŀ��״̬��return
        if (memcmp(goal, s, sizeof(s)) == 0)
            return front;

        int z;
        //��0��λ��
        for (z = 0; z < 9; z++)
            if (!s[z])
                break;
        //��λz����0-2��
        int x = z / 3, y = z % 3;

        for (int d = 0; d < 4; d++)
        {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            //�ж��ƶ��Ƿ�Ϸ�
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                //��չ�½ڵ�
                State &t = st[rear];
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                //�����½ڵ�ľ���ֵ
                dist[rear] = dist[front] + 1;
                //����ɹ�������ұ��޸Ķ�βָ��,���ظ����¸����ǵ�ǰ��
                if (try_to_insert(rear))
                    rear++;
            }
        }
        front++;
    }
    return 0;
}

// Hash�ж��Ƿ��ظ�
const int hashsize = 1000003;
int head[hashsize], nextl[maxstate];

void init_lookup_table()
{
    memset(head, 0, sizeof(head));
}
int hashf(State &s)
{
    int v = 0;
    // 9����ת����9λ��
    for (int i = 0; i < 9; i++)
        v = v * 10 + s[i];
    //ȷ��hash����ֵ�ǲ�����hash���С�ķǸ�����
    return v % hashsize;
}

int try_to_insert(int s)
{
    int h = hashf(st[s]);
    //�ӱ�ͷ��ʼ��������
    int u = head[h];
    while (u)
    {
        //�ҵ��ˣ�����ʧ��
        if (memcmp(st[u], st[s], sizeof(st[s])) == 0)
            return 0;
        //˳�����������
        u = nextl[u];
    }
    nextl[s] = head[h];
    head[h] = s;
    return 1;
}
//��������
void Inputf()
{
    int start;
    int pow = 10;

    cin >> start;

    for (int i = 8; i >= 0; i--)
    {
        st[1][i] = start % pow;
        start /= 10;
    }
}

int main()
{
    Inputf();
    int ans = bfs();

    if (ans > 0)
        cout << dist[ans] << endl;
    else
        cout << "-1" << endl;

    system("pause");

    return 0;
}
