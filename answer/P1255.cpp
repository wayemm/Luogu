#include <iostream>
#include <cstdio>
using namespace std;
int f[5050][5050], len = 1; 
void hpa(int m)             //�߾��ȼӷ���m��ʾ����
{
    for (int i = 1; i <= len; i++)
        f[m][i] = f[m - 1][i] + f[m - 2][i]; //����쳲��������е��ƹ�ʽ
    for (int i = 1; i <= len; i++)           //����ÿһ����λ
    {
        if (f[m][i] >= 10) 
        {
            f[m][i + 1] += f[m][i] / 10;
            f[m][i] %= 10;
            if (f[m][len + 1]) 
                len++;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    f[1][1] = 1; //һ����һ��
    f[2][1] = 2; //����������
    for (int i = 3; i <= n; i++)
        hpa(i);                    //���ø߾��ȼӷ��ĺ���
    for (int i = len; i >= 1; i--) //�������
        printf("%d", f[n][i]);
    return 0;
}