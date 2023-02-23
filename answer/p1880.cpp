#include <iostream>
using namespace std;

int max(int x, int y) //�����ֵ
{
    if (x > y)
        return x;
    else
        return y;
}
int min(int x, int y) //����Сֵ
{
    if (x > y)
        return y;
    else
        return x;
}

int n, sum[300];
int judge(int i, int j)
{
    if (i + j >= n)                                         //�����ڶ���
        return judge(i, n - i - 1) + judge(0, (i + j) % n); //����ѭ���ж�
    else                                                    //��С�ڶ���
        return sum[i + j] - (i > 0 ? sum[i - 1] : 0);       //�жϽ��кϲ���ֵ
}

int main()
{
    int stone[300];
    int dp_min[300][300] = {0}, dp_max[300][300] = {0};
    int i, j, k;
    int min_score, max_score;

    cin >> n; //����ʯͷ����
    for (i = 0; i < n; i++)
        cin >> stone[i]; //����ÿ�Ѹ���

    sum[0] = stone[0]; //��һ�Ѹ���
    for (i = 1; i < n; i++)
        sum[i] = sum[i - 1] + stone[i]; //���㵱ǰ��������ǰ�����ж����ĺ�

    for (i = 1; i < n; i++) //�ϲ�n-1��
    {
        for (j = 0; j < n; j++) //�ж�ÿ���Ƿ�ϲ�
        {
            dp_min[j][i] = 999999;
            dp_max[j][i] = 0;
            for (k = 0; k < i; k++) //�����жϵ���ǰ�ϲ�����
            {
                dp_min[j][i] = min(dp_min[j][i], dp_min[j][k] + dp_min[(j + k + 1) % n][i - k - 1] + judge(j, i)); //��Сֵ
                dp_max[j][i] = max(dp_max[j][i], dp_max[j][k] + dp_max[(j + k + 1) % n][i - k - 1] + judge(j, i)); //���ֵ
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        min_score = min(min_score, dp_min[i][n - 1]); //Ѱ����Сֵ
        max_score = max(max_score, dp_max[i][n - 1]); //Ѱ�����ֵ
    }

    cout << min_score << endl; //��Сֵ
    cout << max_score << endl; //���ֵ

    return 0;
}