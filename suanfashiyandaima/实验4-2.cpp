#include<iostream>
#include<cstring>
using namespace std;

int c,n,w[100],v[100];
int f[101][1001];

int main()
{
	int i,j;
	
	freopen("ex4-2.in","r",stdin);
	
	cin>>c>>n;
	for(i=1;i<=n;i++)
		cin>>w[i];
	for(i=1;i<=n;i++)
		cin>>v[i];
	 
	memset(f,0,sizeof(f));  //≥ı ºªØ
	for (i=1;i<=n;i++)  //dp
  	for (j=1;j<=c;j++)
    {
    	f[i][j]=f[i-1][j];
    	if(w[i]<=j&&f[i][j]<f[i-1][j-w[i]]+v[i]) f[i][j]=f[i-1][j-w[i]]+v[i];
    }
	cout<<f[n][c];
}

