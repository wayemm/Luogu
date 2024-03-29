#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[10001]={1},n,total;
int search(int,int);
int print(int);
int main()
{
    cin>>n;
    search(n,1);                             
         //将要拆分的数n传递给s
    cout<<"total="<<total<<endl; 
         //输出拆分的方案数
}
int search(int s,int t)
{
	int i;
    for (i=a[t-1];i<=s;i++)
    if (i<n)   //当前数i要大于等于前1位数，且不过n
	{
    	a[t]=i;  //保存当前拆分的数i		
    	s-=i;     //s减去数i， s的值将继续拆分          		
    	if (s==0) 
			print(t);        //当s=0时，拆分结束输出结果 
        else
			search(s,t+1);       //当s>0时，继续递归         
    	s+=i;                  //回溯：加上拆分的数，以便产生所有可能的拆分                
    }
}
int print(int t)
{
    cout<<n<<"=";
    for (int i=1;i<=t-1;i++)        //输出一种拆分方案              
		cout<<a[i]<<"+";
    cout<<a[t]<<endl;
    total++;        //方案数累加1    
}
