#include<iostream>
using namespace std;
long fast_pow(long long a,long long b,long long c ){
    long long ans = 1;
    a = a % c;
    while (b)
    {
        /* code */
        if (b&1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b >>=1;
    }
    return ans;
}
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout<<a<<"^"<<b<<" mod "<<
    c<<"="<<fast_pow(a, b, c);
    return 0;
}