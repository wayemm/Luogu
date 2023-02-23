#include <iostream>
using namespace std;

int max(int x, int y) //求最大值
{
    if (x > y)
        return x;
    else
        return y;
}
int min(int x, int y) //求最小值
{
    if (x > y)
        return y;
    else
        return x;
}

int n, sum[300];
int judge(int i, int j)
{
    if (i + j >= n)                                         //若大于堆数
        return judge(i, n - i - 1) + judge(0, (i + j) % n); //进行循环判断
    else                                                    //若小于堆数
        return sum[i + j] - (i > 0 ? sum[i - 1] : 0);       //判断进行合并的值
}

int main()
{
    int stone[300];
    int dp_min[300][300] = {0}, dp_max[300][300] = {0};
    int i, j, k;
    int min_score, max_score;

    cin >> n; //输入石头堆数
    for (i = 0; i < n; i++)
        cin >> stone[i]; //输入每堆个数

    sum[0] = stone[0]; //第一堆个数
    for (i = 1; i < n; i++)
        sum[i] = sum[i - 1] + stone[i]; //计算当前堆数及其前面所有堆数的和

    for (i = 1; i < n; i++) //合并n-1次
    {
        for (j = 0; j < n; j++) //判断每堆是否合并
        {
            dp_min[j][i] = 999999;
            dp_max[j][i] = 0;
            for (k = 0; k < i; k++) //依次判断到当前合并次数
            {
                dp_min[j][i] = min(dp_min[j][i], dp_min[j][k] + dp_min[(j + k + 1) % n][i - k - 1] + judge(j, i)); //最小值
                dp_max[j][i] = max(dp_max[j][i], dp_max[j][k] + dp_max[(j + k + 1) % n][i - k - 1] + judge(j, i)); //最大值
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        min_score = min(min_score, dp_min[i][n - 1]); //寻找最小值
        max_score = max(max_score, dp_max[i][n - 1]); //寻找最大值
    }

    cout << min_score << endl; //最小值
    cout << max_score << endl; //最大值

    return 0;
}