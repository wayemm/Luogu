/*�ֵ������*/ 


#include<iostream>
#include<vector>
#include<algorithm>//��������ʹ����Ϲ�ϵ���㷨
#include<iomanip> //�����������ó���ĺ��� 
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>array;   //������������Ϊint��vector����
	for (size_t i = 1; i <= n; i++)
	{
		array.push_back(i);       //������������Ԫ����ӵ�array�С�
	}
	do
	{
		for (vector<int>::iterator iter = array.begin(); iter != array.end(); iter++)
	{
		cout <<setw(5)<< *iter;  
		//��ʹ��setw(5)���ó����ٵ���������������飨�����л��ɲ��õ������ķ�ʽ�������飩��
		//�˴�������printfȥ���ó���
	}
		cout << endl;
	} while (next_permutation(array.begin(), array.end()));
	return 0;
}
