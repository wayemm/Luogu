#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int);       //����ԭ������ �ж�����
void dfs(int, int, int); //ͬ�ϣ����ܣ���n����ѡk��ֵ�������ǽ������
int n, k;
int ccni = 0; //������ �˴�����ʹ��count�������count����ȷ�����⡣
int zhongcan;
vector<int> array;

int main()
{

    cin >> n >> k;
    for (int i = 0; i != n && cin >> zhongcan; i++)
    {
        array.push_back(zhongcan);
    }
    // sort(array.begin(), array.end()); //���������������
    // for (vector<int>::iterator iter = array.begin(); iter != array.end(); iter++)
    // {
    //     /* code */ cout << *iter << " ";
    // }  //�������������
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
        dfs(m + 1, sum + array[i], i + 1); //�ݹ�
    return;
}
