#include<iostream>


//�������ĳ���һ��Ϊnλ�������а���1��9��2��9��...��n��9��Ԫ�ظ��������ֱ������
//���룺��������n����ʾ���ĳ���
//�����n���������ֱ��ʾ����1��,2����...,n��9�������������ÿո����

















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
