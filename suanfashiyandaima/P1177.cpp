// #include <stdio.h>
// #include <cstdlib>
// int Partition(int *r, int  first, int end);
// void RandQuickSort(int *r, int low, int high);
// int Random(int a, int b);

// int main()
// {
// 	int r[100000];
// 	int i,n;
// 	scanf("%d", &n);
// 	for(i=0;i<n;i++)
// 	scanf("%d", &r[i]);
// 	RandQuickSort(r,0,n-1);
// 	for(int i=0;i<n;i++)
// 	{
// 		printf("%d", r[i]);
// 		printf(" ");
// 	}
// 	printf("\n");
// 	return 0;
	
// }
// int Partition(int *r, int low, int high)          //����
// {	
//    int i = low, j = high;                       //��ʼ������������
//    while (i < j)	
//    {  
//       while (i < j && r[i] <= r[j]) j--;          //�Ҳ�ɨ��
//       if (i < j) { 
// 		int temp = r[i]; r[i] = r[j]; r[j] = temp;     //����С��¼������ǰ��
// 		i++; 
// 	  }
//       while (i < j && r[i] <= r[j]) i++;         //���ɨ��
//       if (i < j) {
// 		int temp = r[i]; r[i] = r[j]; r[j] = temp;     //���ϴ��¼����������
//         j--; 
// 	  }
//    }
//    return i;                                // ������ֵ��¼��λ��
// }
// void RandQuickSort(int *r, int low, int high)         //��������
// {	
//    int k, i, temp;
//    if (low < high) {      
// 	   i = Random(low, high);
// 	   temp = r[low]; r[low] = r[i]; r[i] = temp;
// 	   k = Partition(r, low, high);    //���֣�pivot����ֵ�������е�λ��
//        RandQuickSort(r, low, k-1);      //���������1������������н��п�������
//        RandQuickSort(r, k+1, high);      //���������2�����Ҳ������н��п�������
//    }
// }
// int Random(int a, int b)
// {
//   return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
// }



















#include <stdio.h>
int a[100000 + 100];
void quicksort(int left, int right)
{
	int i = left, j = right, t;
	int mid = a[(left + right) / 2]; // ��ע�⣬�ڴ���Ĺ�����a[(left+right)/2]��ֵ�ǻ�仯��
	while (i <= j)
	{ // i,j��ֵ�ǻ���Ծ��,ѭ������ʱi>j
		while (a[i] < mid)
			i++;
		while (a[j] > mid)
			j--;
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if (i < right)
		quicksort(i, right);                   
	if (left < j)
		quicksort(left, j);
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quicksort(0, n - 1);
	printf("%d", a[0]);
	for (i = 1; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}