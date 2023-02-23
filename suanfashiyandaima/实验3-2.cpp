#include <iostream>
using namespace std;

void BinSearch1(int r[ ], int n, int k);

int main()
{
	int a[100];
	int i,n,k;
	freopen("ex3-2.in","r",stdin);
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	BinSearch1(a,n,k);
	return 0;
}

void BinSearch1(int r[ ], int n, int k)      
{
	int low = 0, high = n - 1;               //设置查找区间，注意数组下标从0开始
	int pos;
	int mid;
	while (low <= high)                //当区间存在时
	{ 
		mid = (low + high) / 2;            
		if (k < r[mid])	high = mid - 1;
		else	if (k > r[mid]) low = mid + 1; 
		else
		{
			cout<<"found , position = "<<mid<<endl;                      //查找成功，返回元素序号
			return ;
		}
	}
	if(low==0) pos=low;  //k比最小值还小，返回low 
	else if(high==n-1)      //k比最大值还大，返回high 
		pos=high;
	else if(r[low]-k>=k-r[high])  //k在a[high]和a[low]之间，返回接近的，注意此时low>high 
		pos=high; 
	else                          //a[low]值更接近k，返回low.如果两者差值相同，返回小的下标 
		pos=low;
	cout<<"not found , closest position = "<<pos<<" data = "<<r[pos]<<endl;
		
}
