/*
p1008������
*/
#include <iostream>
using namespace std;
bool Deng(int, int, int); //����ԭ������  ɸѡ�����������������������ء�
int main()
{
    int A = 1, B = 2, C = 3;
    for (size_t i = 100 / A; C * i < 1000; i++)
    {
        if (Deng(A * i, B * i, C * i) == true)
        {
        }
        else
        {
            cout << A * i << ' ' << B * i << ' '
                 << C * i << endl;
        }
    }
    return 0;
}
bool Deng(int M, int N, int Q)
{

    //�ֱ�9�����ַ���������
    int array[9] = {0};
    array[0] = M / 100;
    array[1] = M % 100 / 10;
    array[2] = M % 10;
    array[3] = N / 100;
    array[4] = N % 100 / 10;
    array[5] = N % 10;
    array[6] = Q / 100;
    array[7] = Q % 100 / 10;
    array[8] = Q % 10;
    for (size_t i = 0; i != 9; i++) //�ж��Ƿ����ظ�����Ҳ����ʹ�ñ�����鼴�����ֳ��ֹ�һ�κ��Ϊһ
    {
        for (size_t j = i + 1; j != 9; j++)
        {
            if (array[i] == array[j] || array[i] == 0 || array[j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}