#include<iostream>
using namespace std;
int main()
{
	int a=0;
	long long dan=1;
	long long sum=0;
	cin>>a;
	if(a<=50)
	{
	
	for(int i=1;i!=a+1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dan*=j;
		}
		sum=sum+dan;
		dan=1;
	}
cout<<sum;	
}
	return 0;
 } 
