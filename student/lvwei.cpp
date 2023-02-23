#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
// bool BiJiao(int, int);
void ChuLi(int *, int, int);
int weishu(int);

int main()
{
    int num;   // 数
    int digit; // k位
    cout << "input ports:";
    cin >> num;
    cout << "Enter the number of digits:";
    cin >> digit;
    int *array = new int[num]; // 申请动态数组
    for (int i = 0; i < num; i++)
    {
        cout << "input " << i + 1 << "：";
        cin >> array[i];
    } // 向组中输入数据
    ChuLi(array, num, digit);
}
// bool BiJiao(int num1, int num2)
//{
//     int c1 = 0, c2 = 0;
//     int nm1 = num1, nm2 = num2;
//     while (nm1)  //两个while函数用于判断输入数据的位数
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
int weishu(int ele) // 返回一个数的位数
{
    int c1 = 0;
    while (ele) // 两个while函数用于判断输入数据的位数
    {
        c1++;
        ele /= 10;
    }
    return c1;
}
void ChuLi(int *array, int num, int digit)
{
    // int temp_num;
    // for (int i = 0; i <= num - 1; ++i) //假设num=5
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
    // }  //冒泡排序？ 直接用sort函数节省代码量
    sort(array, array + num, greater<int>()); // 基于快排
    // if (((sizeof(array)*num)/ sizeof(array[0]))>digit)
    //     //判断数组中所存放的元素个数是否>k   ？？有问题！！ sizeof()动态数组名只是求出了int类型指针的长度！！！
    //     //sizeof(*array)求出其指向的元素的字节数  如此，便不能判断答案是否存在
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