#include<iostream>
#include<cstdio> 
using namespace std;

int a[100],b[100];
int main()
{
	int  i,j,n,len;
	freopen("ex4-1.in","r",stdin);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		b[i]=1;  //³õÊ¼»¯                
	for(i=2;i<=n;i++)  //dp                                   
	{                                                                
    	len=0;                                                 
    	for (j=1;j<=i-1;j++)
      		if (a[i]>=a[j]&&b[j]>len)
        		len=b[j];
      	if(len>0) b[i]=len+1;
  	}
	len=1;
	for (j=2;j<=n;j++)
		if (b[j]>len) 
			len=b[j];
	cout<<len;
}
