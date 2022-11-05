// #include<iostream>
// #include<vector>
// using namespace std;

// int main()
// {
//     int n;
//     int jishu = 0;
//     cin >> n;
//     int *arr = new int[n];
//     int i = 0;
//     while (i<n&&cin>>arr[i])
//     {
//         /* code */
//         i++;
//     }
// for (int i = 0; i < n; i++)
// {
//     /* code */for (int j= i; j < n; j++)
//     {
//         /* code */if (arr[i]>arr[j])
//         {
//             /* code */ jishu++;
//         }
        
//     }
// }
// cout << jishu;
// delete[] arr;
// return 0;
// }  //O(n^2),������
#include <iostream>
using namespace std;
long long n;                    //����n������long long�ʹ�����
const long long maxn = 1000005; //����ֵ��Χ�Դ�һЩ����ֹԽ��
long long a[maxn], r[maxn];     //����ԭ����͸�������
long long ans = 0;
void msort(int s, int t)
{ //���з��η����
    if (s == t)
        return;
    int mid = (s + t) >> 1;           //�ֳ�������
    msort(s, mid), msort(mid + 1, t); //�ֱ���
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t)
    {
        if (a[i] <= a[j])
            r[k] = a[i], k++, i++; //���ǰ��Ⱥ���С�ͼ����������Ƹ���������
        else
            r[k] = a[j], k++, j++, ans += mid - i + 1; //����洢��ͳ�����������
    }

    while (i <= mid)
        r[k] = a[i], k++, i++; //��ʣ�ಿ�ִ��븨�����鲢����ԭ����ʹ֮����
    while (j <= t)
        r[k] = a[j], k++, j++;
    for (int i = s; i <= t; i++)
        a[i] = r[i];
    return;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    msort(0, n - 1);
    cout << ans;
}