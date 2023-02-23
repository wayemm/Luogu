#include <iostream>
#include <cstring>

using namespace std;

typedef int State[9]; //定义“State”类型
const int maxstate = 1000000;
State st[maxstate], goal = {1, 2, 3, 8, 0, 4, 7, 6, 5}; //距离数组
int dist[maxstate];
//打印，父亲编号数组int fa[maxstate];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void init_lookup_table();
int try_to_insert(int s);

// bfs,返回目标状态下的st数组下标
int bfs()
{
    //初始化查找表
    init_lookup_table();
    //不用下标0
    int front = 1, rear = 2;

    while (front < rear)
    {
        //引用
        State &s = st[front];
        //如果找到目标状态就return
        if (memcmp(goal, s, sizeof(s)) == 0)
            return front;

        int z;
        //找0的位置
        for (z = 0; z < 9; z++)
            if (!s[z])
                break;
        //定位z，（0-2）
        int x = z / 3, y = z % 3;

        for (int d = 0; d < 4; d++)
        {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            //判断移动是否合法
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                //拓展新节点
                State &t = st[rear];
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                //更新新节点的距离值
                dist[rear] = dist[front] + 1;
                //如果成功插入查找表，修改队尾指针,若重复则下个覆盖当前表
                if (try_to_insert(rear))
                    rear++;
            }
        }
        front++;
    }
    return 0;
}

// Hash判断是否重复
const int hashsize = 1000003;
int head[hashsize], nextl[maxstate];

void init_lookup_table()
{
    memset(head, 0, sizeof(head));
}
int hashf(State &s)
{
    int v = 0;
    // 9个数转换成9位数
    for (int i = 0; i < 9; i++)
        v = v * 10 + s[i];
    //确保hash函数值是不超过hash表大小的非负整数
    return v % hashsize;
}

int try_to_insert(int s)
{
    int h = hashf(st[s]);
    //从表头开始查找链表
    int u = head[h];
    while (u)
    {
        //找到了，插入失败
        if (memcmp(st[u], st[s], sizeof(st[s])) == 0)
            return 0;
        //顺着链表继续找
        u = nextl[u];
    }
    nextl[s] = head[h];
    head[h] = s;
    return 1;
}
//处理输入
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
