#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
// bool BiJiao(int, int);
void ChuLi(int *, int, int);
int weishu(int);

int main()
{
    int num;   // ��
    int digit; // kλ
    cout << "input ports:";
    cin >> num;
    cout << "Enter the number of digits:";
    cin >> digit;
    int *array = new int[num]; // ���붯̬����
    for (int i = 0; i < num; i++)
    {
        cout << "input " << i + 1 << "��";
        cin >> array[i];
    } // ��������������
    ChuLi(array, num, digit);
}
// bool BiJiao(int num1, int num2)
//{
//     int c1 = 0, c2 = 0;
//     int nm1 = num1, nm2 = num2;
//     while (nm1)  //����while���������ж��������ݵ�λ��
//     {
//         c1++;
//         nm1 /= 10;
//     }
//     while (nm2)
//     {
//         c2++;
//         nm2 /= 10;
//     }
//     int a = num1 * pow(10.0, c2) + num2;
//     int b = num2 * pow(10.0, c1) + num1;
//     if (a > b)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
int weishu(int ele) // ����һ������λ��
{
    int c1 = 0;
    while (ele) // ����while���������ж��������ݵ�λ��
    {
        c1++;
        ele /= 10;
    }
    return c1;
}
void ChuLi(int *array, int num, int digit)
{
    // int temp_num;
    // for (int i = 0; i <= num - 1; ++i) //����num=5
    //{
    //     for (int j = 0; j < num - i - 1; j++)
    //     {
    //         if (BiJiao(array[j], array[j + 1]))
    //         {
    //             temp_num = array[j];
    //             array[j] = array[j + 1];
    //             array[j + 1] = temp_num;
    //         }
    //     }
    // }  //ð������ ֱ����sort������ʡ������
    sort(array, array + num, greater<int>()); // ���ڿ���
    // if (((sizeof(array)*num)/ sizeof(array[0]))>digit)
    //     //�ж�����������ŵ�Ԫ�ظ����Ƿ�>k   ���������⣡�� sizeof()��̬������ֻ�������int����ָ��ĳ��ȣ�����
    //     //sizeof(*array)�����ָ���Ԫ�ص��ֽ���  ��ˣ��㲻���жϴ��Ƿ����
    //{
    //     cout << 0;
    // }
    for (int i = 0; i != num; ++i)
    {
        int sum;
        sum += weishu(array[i]);
        if (sum <=digit)
        {
            cout << array[i];
        }
        
    }

    system("pause");
}