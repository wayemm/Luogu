#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> arra;
void answer(int &k, string &text, vector<string> &arra) // 求拼接后整数的函数
{
    int b = size(arra);
    for (vector<string>::size_type i = 0; i != b; i++)
    {
        int a = size(text);
        if (size(text) <= k)
        {
            text += arra[i];
        }
        while (size(text) > k)
        {
            text.erase(a);
            i++;
            if (i == b)
            {
                return;
            }
            text += arra[i];
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    string text;
    for (int i = 0; i != n && cin >> text; i++) // 将数据输入到容器中
    {
        arra.push_back(text);
    }
    text = "";
    sort(arra.begin(), arra.end(), greater<string>()); // 对输入的数据按照从大到小排序  32 56 123  排序后结果位56 32 123
    answer(k, text, arra);                             // 求拼接后整数的函数
    if (text == "")                                    // 用于在求出拼接后整数后判断该数是否存在
    {
        cout << 0;
    }
    cout << text;
    system("pause");
    return 0;
}
