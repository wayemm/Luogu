/*
斐波那契额数列  递归
加入备忘录算法降低时间空间复杂度
*/

#include <iostream>
using namespace std;
int fibona(int);
int arr[100] = {0};
int main()
{
    int n;
    cin >> n;
    cout << fibona(n);
}
int fibona(int a)
{

    if (arr[a] != 0)
    {
        /* code */ return arr[a];
    }

    if (a == 0 || a == 1)
    {
        return 1; /* code */
    }
    else
    {
        arr[a] = fibona(a - 1) + fibona(a - 2);
        return arr[a];
    }
}