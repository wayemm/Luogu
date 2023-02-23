#include<iostream>  
#include<functional>  
#include<queue>  
#include<vector>  
#include<cstring>
#include<cstdlib>
#define N 3
#define M 3
 
using namespace std;
//求价格不超过d的最小重量，每件机器选择一件 
int d=4; 
int c[N][M]={1,2,3,3,2,1,2,2,2};//所有物品的价格 
int w[N][M]={1,2,3,3,2,1,2,2,2};//所有物品的重量
int min_c[N]={1,1,2},min_w[N]={1,1,2};//每件物品的最小重量，最小价值 
//int c[N][M]={1,4,5,6,2,1,4,5,1};//所有物品的价格 
//int w[N][M]={3,3,3,1,3,4,4,3,2};//所有物品的重量
//int min_c[N]={3,1,2},min_w[N]={1,1,1};//每件物品的最小重量，最小价值 
int index[N];//记录最优结果对应的选择 
//定义了一个全局变量bestw，记录当前获得的满足要求的最小重量，
//当节点当前的重量下限比bestw大的时候，这个节点就不用扩展了
int bestw; 

struct node{
	// 定义N件物品的选取情况，选了就是i(i=0,1,...,M-1).
	int f[N]; 
	//表示当前选择的最后一件机器的编号
	int end; 
	//计算当前的总价格（根据已确定的部分物品选择方案）	
	int csum; 	
	//计算能够达到的重量下限，优先选取下限低的进行扩展，以该值定义优先级。
	//下限由当前的重量加上剩余物品的最小重量和（即每件剩余机器都选价格最低的）,
	//这个下限是理论上的最小值，不一定能达到 
	double wmin;
	int wsum;//计算当前的选择对应的总重量，不能超过d。
	bool operator < (const node &a) const {
        return wmin>a.wmin;//最小值优先
    }
};

void print(struct node p)
{
	int i;
	cout<<"当前已选择了 "<<p.end+1<<" 台机器 ，对应的机器编号为 ：";
	for(i=0;i<=p.end;i++)  
		cout<<p.f[i]+1<<' ';
	cout<<endl;
	cout<<"当前总重量为 : "<<p.wsum<<" , 当前总价格为 ："<<p.csum<<" , 重量下限为 ："<<p.wmin<<endl;
	cout<<endl;
}

int main()
{
	int i,j;
	int sumw,sumc;//价值的上限和下限
	int summinw,summaxw;//计算重量的上限和下限
	int miw,maw;//计算重量上下限时的临时变量 
	int mct;//计算价值下限时的临时变量 
	node p,pp; //构造节点，满足一定条件时压入优先队列 
	priority_queue<node>que; //优先队列 
	
	memset(pp.f,0,sizeof(pp.f));
	pp.end=-1; pp.csum=0;
	summinw=0;
	summaxw=0;
	//贪心法计算重量下限和上限 
	for(i=0;i<N;i++)
	{
		miw=w[i][0];
		maw=w[i][0];
		for(j=1;j<M;j++)
		{
			if(w[i][j]<miw)
				miw=w[i][j];//选取同一物品商家提供的最小重量 
			if(w[i][j]>maw)
				maw=w[i][j];//选取同一物品商家提供的最大重量 
		}
		summinw+=miw; //最小重量求和 
		summaxw+=maw; //最大重量求和 
	}
	pp.wmin=summinw;  //结点接着求下去获得的重量下限 
	pp.wsum=0;  //当前重量和 
	bestw=summaxw;  //最优值赋初值 
	que.push(pp);//将初始节点pp压入优先队列
	while(!que.empty())
	{ 
		//node的成员：f[6](物品选择情况), end(选择到了哪一个物品),
		//csum(当前价值和),wmin(重量下限，所有物品均装入),wsum(当前重量和))
		pp=que.top();
		que.pop(); 
		for(i=0;i<M;i++)  //不同厂商均测试一次 
		{
			p=pp;  //取出当前要扩展的节点 
			p.end+=1; //已选物品范围加1 

			p.f[p.end]=i;//当前物品选择第i个厂商 
			p.wsum=p.wsum+w[p.end][i];//记录选择i件商品后的重量和 
			p.csum=p.csum+c[p.end][i];//记录选择第i件商品后的价值和 
			if(p.end==N-1) //当前节点已经选择到了最后一件物品，无法再选了 
			{
				if(p.wsum<bestw&&p.csum<=d)  //判断当前的重量是否更小，价值是否小于等于d，都满足的话 
				{
					bestw=p.wsum;  //记录当前最优值 
					for(j=0;j<N;j++)
						index[j]=p.f[j];	//记录物品选择情况	
					print(p);			
					continue;
				}
			}			
			mct=p.csum;  //记录当前选择后，价值之和的下限（其后商品每次都选择最便宜的） 
			for(j=p.end+1;j<N;j++)
				mct+=min_c[j];
			if(mct<=d)  //价格未超的话（理想情况下未超） 
			{
				p.wmin=p.wsum;  //计算已有选择下的重量下限（其后商品每次选择最轻的） 
				for(j=p.end+1;j<N;j++)
					p.wmin+=min_w[j];
				if(p.wmin<=bestw)  //如果下限小于之前最优值的话，入队（这样的节点才有获得更优值的可能） 
				{
					que.push(p);
					print(p);
				}
			}
		}
	}
	cout<<bestw<<' ';
	for(i=0;i<N;i++)
		cout<<index[i]+1<<' ';
	cout<<endl;
}

