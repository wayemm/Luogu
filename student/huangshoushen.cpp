#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ����ȽϹ���
bool compare(const int &a, const int &b)
{
    return atoi((to_string(a) + to_string(b)).data()) > atoi((to_string(b) + to_string(a)).data()); // �Ӵ�С����ʹ���ַ���ƴ��
}
int main()
{
    int n, k, r;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)

    {
        cin >> a[i];
        
    }
    vector<int> nums(a, a + n);                                                 // ����һ����������
    sort(nums.begin(), nums.end(), compare);                                    // ʹ��sort���������Զ������
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) // ��С�������
    cout << *iter << endl;
    r = size(nums);
    cout << r;
    return 0;
}