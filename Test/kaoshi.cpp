#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> arra;
void answer(int &k, string &text, vector<string> &arra) // ��ƴ�Ӻ������ĺ���
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
    for (int i = 0; i != n && cin >> text; i++) // ���������뵽������
    {
        arra.push_back(text);
    }
    text = "";
    sort(arra.begin(), arra.end(), greater<string>()); // ����������ݰ��մӴ�С����  32 56 123  �������λ56 32 123
    answer(k, text, arra);                             // ��ƴ�Ӻ������ĺ���
    if (text == "")                                    // ���������ƴ�Ӻ��������жϸ����Ƿ����
    {
        cout << 0;
    }
    cout << text;
    system("pause");
    return 0;
}
