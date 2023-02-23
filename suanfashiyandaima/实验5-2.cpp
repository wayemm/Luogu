#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,k=0;
	int n,p[100],C;
	
	freopen("ex5-2.in","r",stdin);
	cin>>n>>C;
	for(i=0;i<n;i++) cin>>p[i];
	
	sort(p,p+n,greater<int>());
	i=0;
	j=n-1;
	for(;i<j;)
	{
		i++;
		k++;
		if(p[i]+p[j]<=C)
			j--;
	}
	if(i==j) k++;
	cout<<k<<endl;
}
