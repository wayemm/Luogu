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
	int low = 0, high = n - 1;               //���ò������䣬ע�������±��0��ʼ
	int pos;
	int mid;
	while (low <= high)                //���������ʱ
	{ 
		mid = (low + high) / 2;            
		if (k < r[mid])	high = mid - 1;
		else	if (k > r[mid]) low = mid + 1; 
		else
		{
			cout<<"found , position = "<<mid<<endl;                      //���ҳɹ�������Ԫ�����
			return ;
		}
	}
	if(low==0) pos=low;  //k����Сֵ��С������low 
	else if(high==n-1)      //k�����ֵ���󣬷���high 
		pos=high;
	else if(r[low]-k>=k-r[high])  //k��a[high]��a[low]֮�䣬���ؽӽ��ģ�ע���ʱlow>high 
		pos=high; 
	else                          //a[low]ֵ���ӽ�k������low.������߲�ֵ��ͬ������С���±� 
		pos=low;
	cout<<"not found , closest position = "<<pos<<" data = "<<r[pos]<<endl;
		
}
