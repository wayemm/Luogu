#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int);       //函数原型声明 判断素数
void dfs(int, int, int); //同上，功能：从n个数选k个值并将他们进行求和
int n, k;
int ccni = 0; //计数器 此处不能使用count，会出现count不明确的问题。
int zhongcan;
vector<int> array;

int main()
{

    cin >> n >> k;
    for (int i = 0; i != n && cin >> zhongcan; i++)
    {
        array.push_back(zhongcan);
    }
    // sort(array.begin(), array.end()); //给输入的数据排序
    // for (vector<int>::iterator iter = array.begin(); iter != array.end(); iter++)
    // {
    //     /* code */ cout << *iter << " ";
    // }  //输出排序后的数组
    dfs(0, 0, 0);
    cout << ccni << endl;
    return 0;
}
bool isPrime(int n)
{
    for (size_t i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
        else
        {
            return true;
        }
    }
}
void dfs(int m, int sum, int local)
{
    if (m == k)
    {
        if (isPrime(sum))
            ccni++;
        return;
    }
    for (int i = local; i < n; i++)
        dfs(m + 1, sum + array[i], i + 1); //递归
    return;
}
