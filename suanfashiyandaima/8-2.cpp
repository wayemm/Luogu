
#include <iostream>
#include <cstdlib>
using namespace std;
const int n = 10;
int Random(int a, int b);
int FermatPrime(int n);

int main()
{
	int x, flag;
	cin>>x;
	flag = FermatPrime(x);
	if (flag)
		cout<<x<<"������"<<endl;
	else
		cout<<x<<"һ����������"<<endl;
	return 0;
}

int FermatPrime(int n)
{
	int a, b = 1;
	a = Random(2, n-1);              //����[2, n-1]֮���һ���������
	for (int i = 1; i < n; i++)        //����an-1 mod n
		b = (b * a) % n;
	if (b == 1) return 1;              //������������Carmichael��
	else return 0;                   //һ����������
}

int Random(int a, int b)
{
	return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}
