#include <iostream>
using namespace std; 
int MinK(int r[ ],int low,int high,int k);
int Partition(int r[ ], int low, int high);

int main()
{
	int n,k,i,x;
	int r[100]; 
	
	freopen("ex3-1.in","r",stdin);
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>r[i];
	x = MinK(r,0,n-1,k-1);
    cout<<x<<endl;
	return 0;
}

int Partition(int r[ ], int low, int high)          //划分
{	
	int i = low, j=high;                       //初始化待划分区间
	while (i < j)	
	{  
		while (i < j && r[i] <= r[j]) j--;          //右侧扫描
		if (i < j) { 
			int temp = r[i]; r[i] = r[j]; r[j] = temp;     //将较小记录交换到前面
			i++; 
		}
		while (i < j && r[i] <= r[j]) i++;         //左侧扫描
		if (i < j) {
			int temp = r[i]; r[i] = r[j]; r[j] = temp;     //将较大记录交换到后面
			j--; 
		}
	}
	return i;                                // 返回轴值记录的位置
}

int MinK(int r[ ],int low,int high,int k)  //k为第k小元素
{  
    int s;              //s为轴值位置
	s = Partition(r, low, high);
	if (s == k)
		return r[s];
	if(s > k)
		return MinK(r, low, s-1, k);
	else
		return MinK(r, s+1, high, k);
}  
