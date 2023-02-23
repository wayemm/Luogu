#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N][N];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= s2.size(); i++)
        dp[0][i] = i;
    for (int j = 1; j <= s1.size(); j++)
        dp[j][0] = j;
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0;
}
