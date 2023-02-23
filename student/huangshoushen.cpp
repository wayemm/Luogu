#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 定义比较规则
bool compare(const int &a, const int &b)
{
    return atoi((to_string(a) + to_string(b)).data()) > atoi((to_string(b) + to_string(a)).data()); // 从大到小排序，使用字符串拼接
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
    vector<int> nums(a, a + n);                                                 // 输入一个整数数组
    sort(nums.begin(), nums.end(), compare);                                    // 使用sort函数排序，自定义规则
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) // 从小到大输出
    cout << *iter << endl;
    r = size(nums);
    cout << r;
    return 0;
}