#include<iostream>
#include<cstring>
using namespace std;

int set(int *f,int i)
{
	while(i)
	{
		f[i%10]++;
		i=i/10;
	}
}
int main()
{
	int a,b,c,i;
	int flag;
	int count[10];
	for(a=123;a<=987;a++)
	for(b=123;b<=987;b++)
	for(c=123;c<=987;c++)
	{
		if(b/a==2&&b%a==0&&c/a==3&&c%a==0)
		{
			memset(count,0,sizeof(count));
			flag=1;
			set(count,a);
			set(count,b);
			set(count,c);
			for(i=1;i<=9;i++)
				if(count[i]!=1)
				{
					flag=0;
					break;
				}
			if(flag)
				cout<<a<<' '<<b<<' '<<c<<endl;
		}
	}
}

				 
