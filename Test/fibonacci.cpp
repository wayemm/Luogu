/*
斐波那契额数列  递归
加入备忘录算法降低时间空间复杂度
*/



#include <iostream>
using namespace std;
int fibona(int);
int main()
{
    int n;
    int array[100] = {0};
    cin >> n;
    cout << fibona(n);
}
int fibona(int a)
{
    if (array[a]!=0)
    {
        /* code */ return array[a];
    }
    
    if (a== 0||a == 1)
    {
        return 1; /* code */
    }
    else
    {
        array[a] = fibona(a - 1) + fibona(a - 2);
        return array[a];
    }
}