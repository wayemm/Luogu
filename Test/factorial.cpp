#include <iostream>
using namespace std;
int factorial(int); //递归求阶乘
int fact(int);      //循环求阶乘
int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout << fact(n);
}
int factorial(int a)
{
    if (a == 1)     //阶乘停止条件
        return 1; 
    else
    {
        return a * factorial(a - 1);
    }
}
int fact(int n)
{
    int xx = 1;
    for (size_t i = 1; i != n + 1; i++)
    {
        /* code */
        xx *= i;
    }
    return xx;
}