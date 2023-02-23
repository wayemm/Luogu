#include <iostream>
#include <string>
using namespace std;
string n;
int k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        for (unsigned int j = 0; j < n.size(); j++)
            if (n[j] > n[j + 1])
            {
                n.erase(j, 1);
                break;
            }
   unsigned int m = 0;
    while (n[m] == '0')
        m++;
    if (m == n.size())
        cout << 0;
    else
    {
        for (unsigned int i = m; i < n.size(); i++)
            cout << n[i]; 
    }

    cout << endl;
    return 0;
}
