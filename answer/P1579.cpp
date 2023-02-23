#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// p1579,做出质数表

int pn[20000];    // 用于记录已有的素数
int x = 1;        // 记录素数的个数
int sum;          // 记录和
int ans[3] = {0}; // 记录三个加数所属的质数位置
void Pn()
{ // 先把质数表做出来
    pn[0] = 2;
    for (int i = 3; i < 20000; i++)
    {
        bool flag = true;
        for (int j = 0; j < x; j++)
        {
            if (i % pn[j] == 0)
            {
                flag = false;
                break; // 能被一个最小的素数整除，非素数
            }
        }
        if (flag)
        {
            pn[x++] = i;
        }
    }
}
bool flag = false;
void dfs(int count)
{
    if (flag)
    { // 已经找到则无需再找
        return;
    }
    if (count == 3)
    {
        if (pn[ans[0]] + pn[ans[1]] + pn[ans[2]] == sum)
        {
            flag = true;
            cout << pn[ans[0]] << " " << pn[ans[1]] << " " << pn[ans[2]];
        }
        return;
    }
    for (int i = 0; i < x; i++)
    {

        ans[count] = i;
        dfs(count + 1);
    }
}
int main()
{
    Pn();
    cin >> sum;
    dfs(0);
}
