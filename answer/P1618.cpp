#include<iostream>
using namespace std;
bool Deng(int, int, int);//函数原型声明 
int main()
{
	int A = 0, B = 0, C = 0;
	int count = 0;   //计数器
	cin >> A >> B >> C;  //A<B<C
	if (A==0||B==0||C==0)
	{
		cout << "No!!!"; 
		return 0;
	}//排除ABC为0的可能 
	for (size_t i = 100/A;C*i<1000; i++)
	{
		if (Deng(A * i, B * i, C * i) == true)
		{
			
		}
		else
		{
			cout << A * i << ' ' << B * i << ' '
				<< C * i << endl;
			count++;
		} //当不存在答案时输出No!!! 
			
	}
	if (count==0)
	{
		cout << "No!!!";
	}
	return 0;
}
bool Deng(int M, int N, int Q)
{
	
	//分别将9个数字放在数组中
	int array[9] = { 0 };
	array[0] = M / 100;
	array[1] = M % 100 / 10;
	array[2] = M % 10;
	array[3] = N / 100;
	array[4] = N % 100 / 10;
	array[5] = N % 10;
	array[6] = Q / 100;
	array[7] = Q % 100 / 10;
	array[8] = Q % 10;   
	//for (int k = 0; k <9; k++)
	//{
	//	if (array[k] == 0)
	//		return true;
	//}
	//判断是否相同
	for (size_t i = 0; i!=9; i++)
	{
		for (size_t j = i + 1; j !=9; j++) {
			if (array[i]==array[j]||array[i] == 0||array[j]==0)   //判断数位是否相同，相同则返回true，排除此情况。
			{
				return true;
			}
			
		}
	}
}
