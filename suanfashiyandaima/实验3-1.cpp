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

int Partition(int r[ ], int low, int high)          //����
{	
	int i = low, j=high;                       //��ʼ������������
	while (i < j)	
	{  
		while (i < j && r[i] <= r[j]) j--;          //�Ҳ�ɨ��
		if (i < j) { 
			int temp = r[i]; r[i] = r[j]; r[j] = temp;     //����С��¼������ǰ��
			i++; 
		}
		while (i < j && r[i] <= r[j]) i++;         //���ɨ��
		if (i < j) {
			int temp = r[i]; r[i] = r[j]; r[j] = temp;     //���ϴ��¼����������
			j--; 
		}
	}
	return i;                                // ������ֵ��¼��λ��
}

int MinK(int r[ ],int low,int high,int k)  //kΪ��kСԪ��
{  
    int s;              //sΪ��ֵλ��
	s = Partition(r, low, high);
	if (s == k)
		return r[s];
	if(s > k)
		return MinK(r, low, s-1, k);
	else
		return MinK(r, s+1, high, k);
}  
