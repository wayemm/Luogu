 #include<iostream> 
  #include<cstdio> 
  #include<algorithm> 
   using namespace std;
 const int MAXN = 100001;
 inline int read()
{
     char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
     while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
    
}
 int a[MAXN];
 int b[MAXN];
 int ans[MAXN], tot = 0;
 int main() 
{
     int n;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) 
    {
        int p = read();
         a[p] = i;
    }
    for (int i = 1; i <= n; i++) 
    {
        int p = read();
         b[i] = a[p];
    }
     for (int i = 1; i <= n; i++) 
    {
         int p = lower_bound(ans + 1, ans + tot + 1, b[i]) - ans;
         ans[p] = b[i];
         if (p == tot + 1) tot++;
        
    }
     printf("%d", tot);
     return 0;
    
}