#include<iostream>


//假设数的长度一共为n位，求其中包含1个9，2个9，...，n个9的元素个数，并分别输出。
//输入：单个整数n，表示数的长度
//输出：n个整数，分别表示含有1个,2个，...,n个9的整数个数，用空格隔开

















#include<cstring>
using namespace std;

int n;
int begin,end;
int f[10];

int main()
{
	int i,j,count;
	cin>>n;
	begin=1;
	for(i=1;i<n;i++)
		begin=begin*10;
	end=begin*10;
	memset(f,0,sizeof(f));
	for(i=begin;i<end;i++)
	{
		count=0;
		j=i;
		while(j)
		{
			if(j%10==9)
				count++;
			j=j/10;
		}
		f[count]++;
	}
	for(i=1;i<=n;i++)
		cout<<f[i]<<" ";
	cout<<endl;
}
