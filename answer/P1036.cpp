// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// bool isPrime(int);       //����ԭ������ �ж�����
// void dfs(int, int, int); //ͬ�ϣ����ܣ���n����ѡk��ֵ�������ǽ������
// int n, k;
// int ccni = 0; //������ �˴�����ʹ��count�������count����ȷ�����⡣
// int zhongcan;
// vector<int> array;

// int main()
// {

//     cin >> n >> k;
//     for (int i = 0; i != n && cin >> zhongcan; i++)
//     {
//         array.push_back(zhongcan);
//     }
//     // sort(array.begin(), array.end()); //���������������
//     // for (vector<int>::iterator iter = array.begin(); iter != array.end(); iter++)
//     // {
//     //     /* code */ cout << *iter << " ";
//     // }  //�������������
//     dfs(0, 0, 0);
//     cout << ccni << endl;
//     return 0;
// }
// bool isPrime(int n)
// {
//     for (size_t i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//         else
//         {
//             return true;
//         }
//     }
// }
// void dfs(int m, int sum, int local)
// {
//     if (m == k)
//     {
//         if (isPrime(sum))
//             ccni++;
//         return;
//     }
//     for (int i = local; i < n; i++)
//         dfs(m + 1, sum + array[i], i + 1); //�ݹ�
//     return;
// }
//�ƣ�50��



 #include<iostream> 
  using namespace std;
 int n, k, x[21] = {0};
 int sum = 0, ans = 0;
  bool judge(int t)
{
 if (t == 2) return true;
 for (int i = 2; i < t / 2; i++)
    {
         if (t % i == 0) return false;
        
    }
    return true;
    
}
 void dfs(int count, int pos)
{
if (count > k)
    {
         if (judge(sum))
        {
            ans++;
            
        }
         return;

    }
     else
    {
         for (int i = pos + 1; i <= n; i++)
        {
             sum += x[i];
             dfs(count + 1, i);
             sum -= x[i];
            
        }
        
    }
    
}
 int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> x[i];
     dfs(1, 0);
     cout << ans;
     return 0;
    
}