#include<iostream>
using namespace std;
void fuck();
int main()
{
    fuck(); //扯淡的递归，明显的是递归需要递归停止条件。若不存在停止条件，无限循环不停止。崩溃！！！
}
void fuck()
{
    cout << "shit";
    fuck();
}

//递归三要素
// 1.函数的功能
// 2.寻找递归结束条件
// 3.寻找等价关系式
//我们要不断缩小参数的范围，缩小之后，我们可以通过一些辅助的变量或者操作，使原函数的结果不变。