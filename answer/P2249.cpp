#include<iostream>
int n, m, f[1000005], q, pos;

int find(int q)
{
    int l = 0, r = n - 1;
    while (l < r)
    {                          
        int mid = (l + r) / 2; 
        if (q <= f[mid])
            r = mid; 
        else
            l = mid + 1; 
    }
    if (f[l] == q)
        return l + 1;
    else
        return -1;
}

int main()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
       std:: cin >> f[i];
    for (int i = 0; i < m; i++)
    {
        std::cin >> q;
        pos = find(q);
        std::cout << pos << ' ';
    }
    return 0;
}
