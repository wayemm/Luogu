#include <iostream>
using namespace std;
int fibona(int);
int main()
{
    int n;
    cin >> n;
    cout << fibona(n);
}
int fibona(int a)
{
    if (a== 0||a == 1)
    {
        return 1; /* code */
    }
    else
    {
        return fibona(a - 1) + fibona(a - 2);
    }
}