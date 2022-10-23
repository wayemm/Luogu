/*字典序输出*/ 


#include<iostream>
#include<vector>
#include<algorithm>//用来调用使用组合关系的算法
#include<iomanip> //用来调用设置场宽的函数 
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>array;   //申请数据类型为int的vector数组
	for (size_t i = 1; i <= n; i++)
	{
		array.push_back(i);       //将遍历的数组元素添加到array中。
	}
	do
	{
		for (vector<int>::iterator iter = array.begin(); iter != array.end(); iter++)
	{
		cout <<setw(5)<< *iter;  
		//先使用setw(5)设置场宽。再迭代器遍历输出数组（可以切换成不用迭代器的方式遍历数组）；
		//此处可以用printf去设置场宽。
	}
		cout << endl;
	} while (next_permutation(array.begin(), array.end()));
	return 0;
}
