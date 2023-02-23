#include<iostream>
using namespace std;
int v[]={100,50,20,10,5,1};
int main()
{
	int n,num,i;
	cin>>n;
	i=0; 
	for(i=0;i<6;i++)
	{
		num=n/v[i];
		cout<<num<<" ";
		n=n%v[i]; 
	}
	cout<<endl;
}

