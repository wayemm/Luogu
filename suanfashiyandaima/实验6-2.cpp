#include<iostream> 
#include<cstdio>
using namespace std;  

int m,c,bestp;    //物品的个数，背包的容量，最大价值 
int p[100],w[100],x[100],bestx[100];    //物品的价值，物品的重量，x[i]暂存物品的选中情况,最佳时物品的选中情况  
void Backtrack(int i,int cp,int cw)    //cw当前包内物品重量，cp当前包内物品价值 
{  
	int j;     
	if(i>m)  //结束回溯
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
                cw+=w[i]*x[i];   //每个解向量的分量的c与当前的w[i]和前一个解向量分量的cw有关 
				cp+=p[i]*x[i];     
				Backtrack(i+1,cp,cw);  //递归调用 
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

