#include<iostream>
using namespace std;

int main()
{
	int a[100]={32, 27, 1, 24, 27, 44, 52, 32, 1, 44, 27, 31};
	int n=12,i,j,k;
	
/*	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i]; */
	
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
		if(a[j]==a[i])
		{
			for(k=j;k<n-1;k++)
				a[k]=a[k+1];
			n--;
			j--;
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
}
		
