#include<iostream> 
#include<cstdio>
using namespace std;  

int m,c,bestp;    //��Ʒ�ĸ���������������������ֵ 
int p[100],w[100],x[100],bestx[100];    //��Ʒ�ļ�ֵ����Ʒ��������x[i]�ݴ���Ʒ��ѡ�����,���ʱ��Ʒ��ѡ�����  
void Backtrack(int i,int cp,int cw)    //cw��ǰ������Ʒ������cp��ǰ������Ʒ��ֵ 
{  
	int j;     
	if(i>m)  //��������
	{ 
		if(cp>bestp)         
		{ 
        	bestp=cp; 
            for(i=1;i<=m;i++)      
				bestx[i]=x[i];         
		}     
	}     
	else  
		for(j=0;j<=1;j++) 
		{ 
			x[i]=j; 
            if(cw+x[i]*w[i]<=c)               
			{ 
                cw+=w[i]*x[i];   //ÿ���������ķ�����c�뵱ǰ��w[i]��ǰһ��������������cw�й� 
				cp+=p[i]*x[i];     
				Backtrack(i+1,cp,cw);  //�ݹ���� 
				cw-=w[i]*x[i];   
				cp-=p[i]*x[i];              
			}         
		} 
}  

int main() 
{ 
	int i,n;     
	freopen("ex6-2.in","r",stdin); 
	bestp=0; 
	cin>>c; 
	cin>>m; 
	for(i=1;i<=m;i++)    
		cin>>w[i]>>p[i]; 
	Backtrack(1,0,0); 
	cout<<bestp<<endl; 
		for(i=1;i<=m;i++)
			cout<<bestx[i]<<"  ";
		cout<<endl;

} 

