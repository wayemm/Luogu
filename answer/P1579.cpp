#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// p1579,����������

int pn[20000];    // ���ڼ�¼���е�����
int x = 1;        // ��¼�����ĸ���
int sum;          // ��¼��
int ans[3] = {0}; // ��¼������������������λ��
void Pn()
{ // �Ȱ�������������
    pn[0] = 2;
    for (int i = 3; i < 20000; i++)
    {
        bool flag = true;
        for (int j = 0; j < x; j++)
        {
            if (i % pn[j] == 0)
            {
                flag = false;
                break; // �ܱ�һ����С������������������
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
    { // �Ѿ��ҵ�����������
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
